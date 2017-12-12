set(PROJECT_NAME HTKOpenCV)
project(${PROJECT_NAME})

set(${PROJECT_NAME}_SOURCE_FILES
  htkOpenCVUtils.cxx
)

find_package(OpenCV REQUIRED)

add_library(${PROJECT_NAME}Lib ${${PROJECT_NAME}_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}Lib ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME}Lib PUBLIC ${OpenCV_INCLUDE_DIRS})
