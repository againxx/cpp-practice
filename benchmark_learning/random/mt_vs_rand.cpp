#include <vector>
#include <random>
#include <benchmark/benchmark.h>

static void mt_bench(benchmark::State& state) {
    std::vector<int> vec(2 << state.range());
    std::minstd_rand0 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(0, 1000);
    for (auto _ : state) {
        for (auto& i : vec) {
            benchmark::DoNotOptimize(i = dist(gen));
        }
    }
}

static void rand_bench(benchmark::State& state) {
    std::vector<int> vec(state.range());
    for (auto _ : state) {
        for (auto& i : vec) {
            benchmark::DoNotOptimize(i = rand() % 1000);
        }
    }
}

BENCHMARK(mt_bench)->DenseRange(10, 15)->Unit(benchmark::kMicrosecond);
BENCHMARK(rand_bench)->DenseRange(10, 15)->Unit(benchmark::kMicrosecond);
BENCHMARK_MAIN();
