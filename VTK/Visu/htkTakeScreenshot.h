#pragma

#include "htkvtklib_export.h"

// vtk includes
#include <vtkDataObject.h>
#include "vtkSmartPointer.h"

class vtkImageData;
class vtkRenderWindow;

namespace htk
{
  namespace vtk
  {
    namespace visu
    {
      /*
      * Create a screenshot for the current render window
      * @param rw Render window in which the screenshot will be taken
      * @param scale Scale factor which defines the output image size (default is 1 which means that the screenshot
      * will have the same size as the render window.) If the renderwindow size (or renderwindow size * factor)
      * is higher than the screen resolution, then the screenshot size will be clamped to the screen size
      * @return Screenshot as a vtkImageData
      */
      HTKVTKLIB_EXPORT vtkSmartPointer<vtkImageData> TakeScreenshot(vtkRenderWindow* rw, int scale = 1);
    }
  }
}
