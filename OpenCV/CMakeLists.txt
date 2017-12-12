set(PROJECT_NAME HTKOpenCV)
project(${PROJECT_NAME})

set(${PROJECT_NAME}_SOURCE_FILES
  htkOpenCVUtils.cxx
)

add_library( ${PROJECT_NAME}Lib ${${PROJECT_NAME}_SOURCE_FILES})
