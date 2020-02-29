cmake_minimum_required(VERSION 3.8)

project(face-detection VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE main.cpp templateMatching.cpp ViolaJones.cpp)
set(HEADER templateMatching.h ViolaJones.h)
set(OpenCV_DIR C:/opencv/build)

find_package(OpenCV REQUIRED)
add_executable(face-detection ${SOURCE} ${HEADER})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT face-detection)

target_link_libraries( face-detection ${OpenCV_LIBS})