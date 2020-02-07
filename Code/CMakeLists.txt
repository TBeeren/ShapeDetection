cmake_minimum_required(VERSION 3.0.0)
project(ShapeDetection VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED ) 

add_executable(ShapeDetection main.cpp)

target_link_libraries( ShapeDetection ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
