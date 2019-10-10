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
  HTKVTKLIB_EXPORT void CreateSphereSource();
  HTKVTKLIB_EXPORT vtkSmartPointer<vtkImageData> TakeScreenshot(vtkRenderWindow* rw, int scale = 1);

}

#endif
