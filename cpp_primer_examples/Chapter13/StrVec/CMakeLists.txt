cmake_minimum_required(VERSION 3.19.2)

project(StrVec
    VERSION 0.1
    DESCRIPTION "vector class for string"
    LANGUAGES CXX
)

add_executable(str_vec)

target_sources(str_vec
    PRIVATE
        main.cpp
        str_vec.cpp
)

target_compile_features(str_vec
    PRIVATE
        cxx_std_17
)
