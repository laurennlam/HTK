set(PROJECT_NAME HTKCommon)
project(${PROJECT_NAME})

set(INCLUDE_DIRS
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/IO
)

set(SOURCE_FILES
  IO/htkWriteOutputFile.cxx
)

add_library(${PROJECT_NAME}Lib ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME}Lib PUBLIC ${INCLUDE_DIRS})

generate_export_header(${PROJECT_NAME}Lib)
