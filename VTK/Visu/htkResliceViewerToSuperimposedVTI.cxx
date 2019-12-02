#include "htkResliceViewerToSuperimposedVTI.h"

// VTK includes
#include <vtkCallbackCommand.h>
#include <vtkImageActor.h>
#include <vtkImageProperty.h>
#include <vtkLookupTable.h>
#include <vtkNew.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkResliceImageViewer.h>
#include <vtkXMLImageDataReader.h>

class SynchronizeCallback : public vtkCommand
{
public:
  static SynchronizeCallback *New()
  {
    return new SynchronizeCallback;
  }

  void SetSegmentedViewer(vtkResliceImageViewer* viewer)
  {
    this->ModifiedViewer = viewer;
  }

  virtual void Execute(vtkObject *caller, unsigned long, void*)
  {
    if (!this->ModifiedViewer)
    {
      return;
    }

    /* Get caller viewer */

    vtkResliceImageViewer* viewerCaller =
      reinterpret_cast<vtkResliceImageViewer*>(caller);

    /* Update slice */

    if (viewerCaller)
    {
      int sliceID = viewerCaller->GetSlice();
      if (sliceID < 0 || sliceID > this->ModifiedViewer->GetSliceMax())
      {
        std::cerr << "Warning : The slice id " << sliceID << " is out of the range." << std::endl;
        return;
      }
      else
      {
        this->ModifiedViewer->SetSlice(sliceID);
      }
    }
  }
private:
  vtkResliceImageViewer* ModifiedViewer;
};

void htk::vtk::visu::ResliceViewerToSuperimposedVTI(const std::string& firstPath, const std::string& secondPath)
{
  /* Setup view */

  vtkNew<vtkRenderWindow> renderWindow;
  renderWindow->SetSize(1000, 1000);
  // We need to define two layers because each vtkResliceImageViewer has a renderer
  renderWindow->SetNumberOfLayers(2);
  vtkNew<vtkRenderWindowInteractor> interactor;
  interactor->SetRenderWindow(renderWindow.Get());

  /* Read data */

  vtkNew<vtkXMLImageDataReader> reader;
  reader->SetFileName(firstPath.c_str());
  reader->Update();

  vtkNew<vtkXMLImageDataReader> readerSegmented;
  readerSegmented->SetFileName(secondPath.c_str());
  readerSegmented->Update();

  /* Define main viewer */

  vtkNew<vtkResliceImageViewer> viewer;
  viewer->SetRenderWindow(renderWindow.Get());
  viewer->SetInputData(reader->GetOutput());
  int midslice = viewer->GetSliceMax() / 2;
  viewer->SetSlice(midslice);
  viewer->SetSliceOrientationToXY();

  viewer->SetupInteractor(interactor);
  viewer->GetRenderer()->SetLayer(0);

  /* Define second image viewer */

  vtkNew<vtkResliceImageViewer> viewerSegmented;
  viewerSegmented->SetRenderWindow(renderWindow.Get());
  viewerSegmented->SetInputData(readerSegmented->GetOutput());
  int midsliceSegmented = viewerSegmented->GetSliceMax() / 2;
  viewerSegmented->SetSlice(midsliceSegmented);
  viewerSegmented->SetSliceOrientationToXY();

  // Don't enable image interaction on the second image
  // If so, then events will be eaten by the viewer 2
  // viewerSegmented->SetupInteractor(interactor);

  viewerSegmented->GetRenderer()->SetLayer(1);

  // Links camera of both viewers
  viewerSegmented->GetRenderer()->SetActiveCamera(viewer->GetRenderer()->GetActiveCamera());

  /* Parametrize opacity for segmented image */

  vtkNew<vtkLookupTable> lut;
  lut->SetNumberOfColors(2);
  lut->SetTableValue(0, 0.0, 0.0, 0.0, 0.0);
  lut->SetTableValue(1, 1.0, 0.0, 0.0, 1.0);
  lut->Build();

  // Define a lookup table to the segmented image
  // Black pixels will be transparent
  viewerSegmented->GetImageActor()->GetProperty()->SetLookupTable(lut);
  viewerSegmented->GetImageActor()->SetOpacity(0.5);

  /* Define callback to synchronize views */

  // When the first viewer slice is updated, then the second viewer will be
  // updated to the same slice
  vtkNew<SynchronizeCallback> callback;
  callback->SetSegmentedViewer(viewerSegmented.Get());
  viewer->AddObserver(vtkCommand::ModifiedEvent, callback);

  /* Launch view */

  viewer->GetRenderer()->ResetCamera();
  interactor->Start();
}
