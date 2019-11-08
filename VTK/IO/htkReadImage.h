#pragma once
#include "htkvtklib_export.h"

// STL includes
#include "string"

// VTK include
#include "vtkSmartPointer.h"
class vtkImageData;

namespace htk
{
  namespace vtk
  {
    namespace io
    {
      /*
      * Read an image data (png or jpg)
      * @param path Full path to the input image file. The file extension has
      * to be in lowercase (.png or .jpg or .jpeg)
      * @return vtkImageData
      */
      HTKVTKLIB_EXPORT vtkSmartPointer<vtkImageData> ReadImage(const std::string& path);
    }
  }
}
