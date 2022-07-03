#include <vector>
#include <benchmark/benchmark.h>

static void not_reserve_benchmark(benchmark::State& state) {
    std::vector<int> vec;
    const std::size_t N = state.range();

    for (auto _ : state) {
        for (std::size_t i = 0; i < N; ++i) {
            vec.push_back(i);
            benchmark::ClobberMemory();
        }
    }
}

static void reserve_benchmark(benchmark::State& state) {
    std::vector<int> vec;
    const std::size_t N = state.range();
    vec.reserve(N);

    for (auto _ : state) {
        for (std::size_t i = 0; i < N; ++i) {
            vec.push_back(i);
            benchmark::ClobberMemory();
        }
    }
}

BENCHMARK(not_reserve_benchmark)->Range(1 << 8, 1 << 10);
BENCHMARK(reserve_benchmark)->Range(1 << 8, 1 << 10);
BENCHMARK_MAIN();
