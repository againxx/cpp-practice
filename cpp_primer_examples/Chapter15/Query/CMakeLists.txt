cmake_minimum_required(VERSION 3.20)

project(complex_query
    VERSION 0.1
    DESCRIPTION "complex text query example"
    LANGUAGES CXX
)

add_executable(complex_query
    main.cpp
    query_result.cpp
    query.cpp
    text_query.cpp
    and_query.cpp
    or_query.cpp
)
