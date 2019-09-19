#ifndef htkvtkutils_h
#define htkvtkutils_h

#include "htkvtklib_export.h"

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

HTKVTKLIB_EXPORT void CreateSphereSource();

}

#endif
