#pragma once
#include "htkvtklib_export.h"

// STL includes
#include "string"

namespace htk
{
  namespace vtk
  {
    namespace visu
    {
      /*
      * Read and display two VTI
      * Use the resliceViewer to allow windows level and slice
      * @param path Full path to the input image file. The file extension has
      * to be in lowercase (.png or .jpg or .jpeg)
      * @return vtkImageData
      */
      HTKVTKLIB_EXPORT void ResliceViewerToSuperimposedVTI(
        const std::string& path1, const std::string& path2);
    }
  }
}
