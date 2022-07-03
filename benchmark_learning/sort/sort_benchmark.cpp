#include <vector>
#include <random>
#include <algorithm>
#include <benchmark/benchmark.h>

static void sort_benchmark(benchmark::State& state) {
    std::vector<int> vec(state.range());
    std::mt19937 mt_gen(std::random_device{}());
    std::uniform_int_distribution<> int_dist(0, 10000);
    std::generate(vec.begin(), vec.end(), [&]{ return int_dist(mt_gen); });

    for (auto _ : state) {
        std::sort(vec.begin(), vec.end());
    }
    state.SetComplexityN(state.range());
}

BENCHMARK(sort_benchmark)->Range(1 << 8, 1 << 10)->Complexity(benchmark::oNLogN);

BENCHMARK_MAIN();
