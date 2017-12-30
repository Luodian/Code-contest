cmake_minimum_required(VERSION 3.8)
project(A)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cmake-build-debug/A.cpp cmake-build-debug/A.h)
add_executable(A ${SOURCE_FILES})