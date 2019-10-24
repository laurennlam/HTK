// htk includes
#include "htkTakeScreenshot.h"

// vtk includes
#include <vtkImageData.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkWindowToImageFilter.h>

vtkSmartPointer<vtkImageData> htk::vtk::visu::TakeScreenshot(vtkRenderWindow* rw, int scale)
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
