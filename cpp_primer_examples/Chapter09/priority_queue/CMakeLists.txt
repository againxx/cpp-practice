cmake_minimum_required(VERSION 3.20)

project(custom_priority_comparator
    VERSION 0.1
    DESCRIPTION "test how to use static method as custom comparator"
    LANGUAGES CXX
)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_custom_priority_comparator
    test_custom_priority_comparator.cpp
    custom_priority_comparator.cpp
)

target_link_libraries(test_custom_priority_comparator
    PRIVATE
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_custom_priority_comparator)
