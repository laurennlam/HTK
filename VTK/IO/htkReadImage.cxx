#include "htkReadImage.h"

// VTK includes
#include <vtkImageData.h>
#include <vtkImageReader2.h>
#include <vtkJPEGReader.h>
#include <vtkPNGReader.h>


vtkSmartPointer<vtkImageData> htk::vtk::io::ReadImage(const std::string& path)
{
  vtkImageReader2* reader = nullptr;
  if (path.find(".png") != std::string::npos)
  {
    reader = vtkPNGReader::New();
  }
  if (path.find(".jpg") != std::string::npos ||
    path.find(".jpeg") != std::string::npos)
  {
    reader = vtkJPEGReader::New();
  }

  if (reader != nullptr)
  {
    reader->SetFileName(path.c_str());
    reader->Update();
    vtkSmartPointer<vtkImageData> output = reader->GetOutput();
    reader->Delete();
    return output;
  }
  return nullptr;
}
