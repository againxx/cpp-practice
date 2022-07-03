cmake_minimum_required(VERSION 3.20)

project(algorithm_test
    VERSION 0.1
    DESCRIPTION "test different std algorithms"
    LANGUAGES CXX
)

find_package(TBB REQUIRED)

add_executable(reduce_vs_accumulate
    reduce_vs_accumulate.cpp
)

target_link_libraries(reduce_vs_accumulate
    PRIVATE
        ${TBB_IMPORTED_TARGETS}
)

target_compile_features(reduce_vs_accumulate
    PRIVATE
        cxx_std_17
)
