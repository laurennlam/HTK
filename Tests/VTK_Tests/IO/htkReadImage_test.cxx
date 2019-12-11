#include "catch.hpp"

#include "htkReadImage.h"

TEST_CASE("VTK_IO", "[ReadImage]")
{
  vtkSmartPointer<vtkImageData> image = htk::vtk::io::ReadImage("bad path");
  
  REQUIRE(true);
}
