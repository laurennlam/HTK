#ifndef htkvtkutils_h
#define htkvtkutils_h

#include "htkvtklib_export.h"

// vtk includes
#include <vtkDataObject.h>
#include "vtkSmartPointer.h"

class vtkImageData;
class vtkRenderWindow;


namespace htk
{

  /**
  * Open a VTK window ans display the dataObject inside.
  *
  * @param dataObject VTK Object to be displayed
  * @param attributeType Determines if the color is based on a cell array or
  * a point array. Possible values are: vtkDataObject::POINT and
  * vtkDataObject::CELL.
  * @ return True if the data object could be displayed, false otherwise
  */
  HTKVTKLIB_EXPORT bool DisplayVtkDataObject(vtkDataObject* dataObject, int attributeType = vtkDataObject::POINT);

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

#endif
