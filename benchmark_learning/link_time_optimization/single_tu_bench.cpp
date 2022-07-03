#include <benchmark/benchmark.h>

void baseMMul(const int* a, const int* b, int* c, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c[i * N + j] += a[i * N + k] * b[k * N + j];
            }
        }
    }
}

static void singleTU(benchmark::State& state) {
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

BENCHMARK(singleTU)->DenseRange(8, 10)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
