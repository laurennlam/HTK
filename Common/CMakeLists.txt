set(PROJECT_NAME HTKCommon)
project(${PROJECT_NAME})

set(SOURCE_FILES
  htkMath.cxx
  htkIO.cxx
)

add_library(${PROJECT_NAME}Lib ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME}Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

generate_export_header(${PROJECT_NAME}Lib)
