#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <benchmark/benchmark.h>

static void accumulate_benchmark(benchmark::State& state) {
  auto N = 1 << 10;

  std::vector<int> v(N);
  std::generate(v.begin(), v.end(), []{ return rand() % 100; });

  int result = 0;

  for (auto _ : state) {
      benchmark::DoNotOptimize(result = std::accumulate(v.cbegin(), v.cend(), 0));
  }
}

BENCHMARK(accumulate_benchmark);

BENCHMARK_MAIN();
