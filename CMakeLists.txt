set(Qt6_DIR "D:\\QT\\6.2.4\\mingw_64\\lib\\cmake\\Qt6")
cmake_minimum_required(VERSION 3.10)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

message("Qt6_DIR = " ${Qt6_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE "Debug")

project(cypan_prj VERSION 0.1 LANGUAGES CXX)

add_subdirectory(test)
add_subdirectory(cypan)