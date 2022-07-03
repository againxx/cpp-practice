cmake_minimum_required(VERSION 3.19.2)

project(message
    VERSION 0.1
    DESCRIPTION "Message and Folder Classes"
    LANGUAGES CXX
)

add_executable(message)

target_sources(message
    PRIVATE
        main.cpp
        message.cpp
        folder.cpp
)
