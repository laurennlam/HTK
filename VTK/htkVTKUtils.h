#ifndef htkvtkutils_h
#define htkvtkutils_h

#include "htkvtklib_export.h"

// vtk includes
#include <vtkDataObject.h>

namespace htk
{

  // Open a VTK window ans display the dataObject inside.
  //
  // The attribute type determines if the color is based
  // on a cell array or a point array. Possible values are:
  // vtkDataObject::POINT
  // vtkDataObject::CELL
  HTKVTKLIB_EXPORT bool DisplayVtkDataObject(vtkDataObject* dataObject, int attributeType = vtkDataObject::POINT);

}

#endif
