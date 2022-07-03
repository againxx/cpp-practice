#include <string>
#include <vector>
#include <benchmark/benchmark.h>

static void stringBench(benchmark::State& state) {
    int len = state.range(0);

    std::vector<std::string> str_vec;
    str_vec.reserve(10000);

    for (auto _ : state) {
        for (std::size_t i = 0; i < 10000; ++i) {
            std::string str(len, 'x');
            str_vec.push_back(str);
        }
    }
}

BENCHMARK(stringBench)->DenseRange(0, 32);
