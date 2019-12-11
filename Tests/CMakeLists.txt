# Create a static library that will be used with all subtests
# The main file that will be launched all tests
add_library(htkTestBase STATIC
  catch.hpp
  mainTest.cxx
)

target_include_directories(htkTestBase PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(VTK_Tests)
# add_subdirectory(Common_Tests)
