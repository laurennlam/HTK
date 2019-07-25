set(PROJECT_NAME HTKVTK)
project(${PROJECT_NAME})

set(SOURCE_FILES
  htkVTKUtils.cxx
)

find_package(VTK REQUIRED)

add_library(${PROJECT_NAME}Lib ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}Lib PRIVATE ${VTK_LIBRARIES})
target_include_directories(${PROJECT_NAME}Lib PUBLIC ${VTK_INCLUDE_DIRS})
