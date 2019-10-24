// htk includes
#include "htkDisplayVtkDataObject.h"

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

bool htk::vtk::visu::DisplayVtkDataObject(vtkDataObject* dataObject, int attributeType)
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
