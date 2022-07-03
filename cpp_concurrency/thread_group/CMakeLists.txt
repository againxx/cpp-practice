cmake_minimum_required(VERSION 3.20)

project(thread_group
    VERSION 0.1
    DESCRIPTION "thread group examples"
    LANGUAGES CXX
)

find_package(Threads REQUIRED)

add_executable(thread_group
    thread_group.cpp
)

target_link_libraries(thread_group
    PRIVATE
        Threads::Threads
)

target_compile_features(thread_group
    PRIVATE
        cxx_std_20
)
