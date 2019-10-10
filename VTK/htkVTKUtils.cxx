// htk includes
#include "htkVTKUtils.h"

// vtk includes
#include <vtkActor.h>
#include <vtkDataArray.h>
#include <vtkDataSet.h>
#include <vtkDataSetAttributes.h>
#include <vtkDataSetMapper.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkNew.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkWindowToImageFilter.h>

namespace htk
{
  bool DisplayVtkDataObject(vtkDataObject* dataObject, int attributeType)
  {
    vtkDataSet* dataset = vtkDataSet::SafeDownCast(dataObject);
    if (!dataset)
    {
      std::cerr << "This dataset type is not supported by DisplayVtkDataObject." << std::endl;
      return false;
    }

    vtkNew<vtkDataSetMapper> mapper;
    mapper->SetInputData(dataset);

    vtkDataSetAttributes* attributes = dataset->GetAttributes(attributeType);
    if (attributes)
    {
      mapper->SetScalarRange(attributes->GetScalars()->GetRange());
    }

    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper.Get());

    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(actor.Get());

    vtkNew<vtkRenderWindow> renderWindow;
    renderWindow->AddRenderer(renderer.Get());

    vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
    renderWindowInteractor->SetRenderWindow(renderWindow.Get());

    vtkNew<vtkInteractorStyleTrackballCamera> interactorStyle;
    renderWindowInteractor->SetInteractorStyle(interactorStyle.Get());

    renderWindow->Render();
    renderWindowInteractor->Start();

    return true;
  }

  /*
  * Create a screenshot for the current render window
  * @param rw Render window in which the screenshot will be taken
  * @param scale Scale factor which defines the output image size (default is 1 which means that the screenshot
  * will have the same size as the render window.) If the renderwindow size (or renderwindow size * factor)
  * is higher than the screen resolution, then the screenshot size will be clamped to the screen size
  * @return Screenshot as a vtkImageData
  */
  vtkSmartPointer<vtkImageData> TakeScreenshot(vtkRenderWindow* rw, int scale)
  {
    if (!rw)
    {
      std::cerr << "No renderwindow has been set" << std::endl;
      return nullptr;
    }

    vtkSmartPointer<vtkWindowToImageFilter> windowToImageFilter =
      vtkSmartPointer<vtkWindowToImageFilter>::New();
    windowToImageFilter->SetInput(rw);
    windowToImageFilter->SetScale(scale);
    windowToImageFilter->Update();

    vtkSmartPointer<vtkImageData> output = windowToImageFilter->GetOutput();
    return output;
  }

}
