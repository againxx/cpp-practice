cmake_minimum_required(VERSION 3.10)

project(function_pointer
    VERSION 0.1
    DESCRIPTION "cpp weekly example"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(function_pointer function_pointer.cpp)
