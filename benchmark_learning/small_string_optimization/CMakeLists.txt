cmake_minimum_required(VERSION 3.20)

project(small_string_optimization_benchmark
    VERSION 0.1
    DESCRIPTION "small string opitimization benchmark"
    LANGUAGES CXX
)


find_package(benchmark REQUIRED)

add_executable(small_string_benchmark small_string_benchmark.cpp)

target_link_libraries(small_string_benchmark
    PRIVATE
        benchmark::benchmark
        benchmark::benchmark_main
)
