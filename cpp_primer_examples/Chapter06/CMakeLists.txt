cmake_minimum_required(VERSION 3.16)

project(InitList
    VERSION 0.1
    DESCRIPTION "Example of initializer_list"
    LANGUAGES CXX CUDA
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(InitList)

target_sources(InitList
    PRIVATE
        InitList.cpp
)
