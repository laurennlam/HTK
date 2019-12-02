set(PROJECT_NAME HTKVTK)
project(${PROJECT_NAME})

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

set(INCLUDE_DIRS
  ${VTK_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/IO
  ${CMAKE_CURRENT_SOURCE_DIR}/Visu
)

set(SOURCE_FILES
  IO/htkReadImage.cxx
  Visu/htkDisplayVtkDataObject.cxx
  Visu/htkResliceViewerToSuperimposedVTI.cxx
  Visu/htkTakeScreenshot.cxx
)

add_library(${PROJECT_NAME}Lib ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}Lib PUBLIC ${VTK_LIBRARIES})
target_include_directories(${PROJECT_NAME}Lib PUBLIC ${INCLUDE_DIRS})

generate_export_header(${PROJECT_NAME}Lib)
