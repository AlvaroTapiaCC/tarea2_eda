cmake_minimum_required(VERSION 3.10)
project(poscode
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp src/linkedList.cpp src/node.cpp src/test.cpp src/poscode.cpp src/utils.cpp)
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)