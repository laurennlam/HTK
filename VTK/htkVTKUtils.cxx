// htk includes
#include "htkVTKUtils.h"

// vtk includes
#include <vtkActor.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSphereSource.h>

namespace htk
{

void CreateSphereSource()
{
  vtkNew<vtkSphereSource> sphereSource;
  sphereSource->SetCenter(0.0, 0.0, 0.0);
  sphereSource->SetRadius(5.0);

  vtkNew<vtkPolyDataMapper> mapper;
  mapper->SetInputConnection(sphereSource->GetOutputPort());

  vtkNew<vtkActor> actor;
  actor->SetMapper(mapper.Get());

  vtkNew<vtkRenderer> renderer;
  renderer->AddActor(actor.Get());
  renderer->SetBackground(.3, .6, .3);

  vtkNew<vtkRenderWindow> renderWindow;
  renderWindow->AddRenderer(renderer.Get());

  vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
  renderWindowInteractor->SetRenderWindow(renderWindow.Get());

  renderWindow->Render();
  renderWindowInteractor->Start();
}

}
