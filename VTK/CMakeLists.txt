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

configure_file(
  ${CMAKE_SOURCE_DIR}/CMake/HTKConfig.cmake.in
  "${CMAKE_BINARY_DIR}/HTKConfig.cmake" @ONLY)

export(TARGETS ${PROJECT_NAME}Lib
  FILE "${CMAKE_BINARY_DIR}/HTKTargets.cmake")
