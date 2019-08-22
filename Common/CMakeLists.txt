set(PROJECT_NAME HTKCommon)
project(${PROJECT_NAME})

set(SOURCE_FILES
  htkMath.cxx
)

add_library(${PROJECT_NAME}Lib ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME}Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
