#include <algorithm>
#include <execution>
#include <vector>
#include <random>
#include <benchmark/benchmark.h>

template<typename Policy>
static void BM_DotProduct(benchmark::State& state, Policy execution_policy) {
    std::vector<double> firstVec(state.range(0));
    std::vector<double> secondVec(state.range(0));

    std::default_random_engine random_engine;
    std::uniform_real_distribution<> real_dist(-1.0, 1.0);
    std::generate(std::execution::par, firstVec.begin(), firstVec.end(),
                  [&]{return real_dist(random_engine);});
    std::generate(std::execution::par, secondVec.begin(), secondVec.end(),
                  [&]{return real_dist(random_engine);});

    for (auto _ : state) {
        double res = std::transform_reduce(execution_policy, firstVec.cbegin(),
                                           firstVec.cend(), secondVec.cbegin(),
                                           0.0,
                                           std::plus<double>{},
                                           std::multiplies<double>{});
        benchmark::DoNotOptimize(res);
    }
}

BENCHMARK_CAPTURE(BM_DotProduct, seq, std::execution::seq)->RangeMultiplier(10)->Range(1000, 1000000)->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(BM_DotProduct, par, std::execution::par)->RangeMultiplier(10)->Range(1000, 1000000)->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(BM_DotProduct, par_unseq, std::execution::par_unseq)->RangeMultiplier(10)->Range(1000, 1000000)->Unit(benchmark::kMicrosecond);
