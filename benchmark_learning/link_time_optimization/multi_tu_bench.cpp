#include <benchmark/benchmark.h>

void baseMMul(const int* a, const int* b, int* c, int N);

static void multiTU(benchmark::State& state) {
    const int N = 1 << state.range();

    int* a = new int[N * N]();
    int* b = new int[N * N]();
    int* c = new int[N * N]();

    while (state.KeepRunning()) {
        baseMMul(a, b, c, N);
    }

    delete [] a;
    delete [] b;
    delete [] c;
}

BENCHMARK(multiTU)->DenseRange(8, 10)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
