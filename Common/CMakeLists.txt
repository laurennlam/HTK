set(PROJECT_NAME HTKCommon)
project(${PROJECT_NAME})

set(${PROJECT_NAME}_SOURCE_FILES
  htkMath.cxx
)

add_library( ${PROJECT_NAME}Lib ${${PROJECT_NAME}_SOURCE_FILES})
