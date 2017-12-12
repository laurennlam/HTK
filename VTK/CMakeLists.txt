set(PROJECT_NAME HTKVTK)
project(${PROJECT_NAME})

set(${PROJECT_NAME}_SOURCE_FILES
  htkVTKUtils.cxx
)

find_package(VTK REQUIRED)

add_library(${PROJECT_NAME}Lib ${${PROJECT_NAME}_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}Lib ${VTK_LIBRARIES})
target_include_directories(${PROJECT_NAME}Lib PUBLIC ${VTK_INCLUDE_DIRS})
