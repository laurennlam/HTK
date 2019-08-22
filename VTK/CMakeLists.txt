set(PROJECT_NAME HTKVTK)
project(${PROJECT_NAME})

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

set(SOURCE_FILES
  htkVTKUtils.cxx
)

add_library(${PROJECT_NAME}Lib ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}Lib PUBLIC ${VTK_LIBRARIES})
target_include_directories(${PROJECT_NAME}Lib PUBLIC ${VTK_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})
