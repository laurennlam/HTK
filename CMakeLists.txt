cmake_minimum_required(VERSION 3.10)
project(HTK)

include(GenerateExportHeader)

# HTK doesn't require C++ 14 and higher
set(CMAKE_CXX_STANDARD 11)

# TODO is it useful ?
#add_subdirectory(CMake)

option(BUILD_SHARED_LIBS "Build HTK as a shared library (vs. static library)." ON)

# enable HTK modules
option(HTK_USE_COMMON "Enable common C++ features" ON)
option(HTK_USE_VTK "Enable VTK features" OFF)
option(HTK_USE_ITK "Enable ITK features" OFF)
option(HTK_USE_OPENCV "Enable OpenCV features" OFF)

set(LibsList )

if(HTK_USE_COMMON)
  add_subdirectory(Common)
  list(APPEND LibsList HTKCommonLib)
endif(HTK_USE_COMMON)

if(HTK_USE_VTK)
  add_subdirectory(VTK)
  list(APPEND LibsList HTKVTKLib)
endif(HTK_USE_VTK)

if(HTK_USE_ITK)
  add_subdirectory(ITK)
  list(APPEND LibsList HTKITKLib)
endif(HTK_USE_ITK)

if(HTK_USE_OPENCV)
  add_subdirectory(OpenCV)
  list(APPEND LibsList HTKOPENCVLib)
endif(HTK_USE_OPENCV)

configure_file(
  ${CMAKE_SOURCE_DIR}/CMake/HTKConfig.cmake.in
  "${CMAKE_BINARY_DIR}/HTKConfig.cmake" @ONLY)

export(TARGETS ${LibsList}
  FILE "${CMAKE_BINARY_DIR}/HTKTargets.cmake")

enable_testing()
add_subdirectory(Tests)