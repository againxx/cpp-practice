#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <execution>
#include <benchmark/benchmark.h>

static void SequenceBenchmark(benchmark::State& state) {
    int N = 1 << state.range();
    std::srand(std::time(NULL));

    std::vector<int> v;
    v.reserve(N);

    for (std::size_t i = 0; i < N; ++i) {
        v.emplace_back(rand() % 2);
    }

    for (auto _ : state) {
        std::sort(std::execution::seq, v.begin(), v.end());
    }
}

static void ParallelBenchmark(benchmark::State& state) {
    int N = 1 << state.range();
    std::srand(std::time(NULL));

    std::vector<int> v;
    v.reserve(N);

    for (std::size_t i = 0; i < N; ++i) {
        v.emplace_back(rand() % 2);
    }

    for (auto _ : state) {
        std::sort(std::execution::par, v.begin(), v.end());
    }
}

static void ParallelUnsequenceBenchmark(benchmark::State& state) {
    int N = 1 << state.range();
    std::srand(std::time(NULL));

    std::vector<int> v;
    v.reserve(N);

    for (std::size_t i = 0; i < N; ++i) {
        v.emplace_back(rand() % 2);
    }

    for (auto _ : state) {
        std::sort(std::execution::par_unseq, v.begin(), v.end());
    }
}

BENCHMARK(SequenceBenchmark)->DenseRange(15, 22)->Unit(benchmark::kMillisecond);
BENCHMARK(ParallelBenchmark)->DenseRange(15, 22)->Unit(benchmark::kMillisecond);
BENCHMARK(ParallelUnsequenceBenchmark)->DenseRange(15, 22)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
