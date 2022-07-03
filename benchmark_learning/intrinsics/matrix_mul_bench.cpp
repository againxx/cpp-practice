#include <benchmark/benchmark.h>

void matrix_vector(float *m, float *v, float *r, std::size_t dim) {
    for (std::size_t i = 0; i < dim; ++i) {
        for (std::size_t j = 0; j < dim; ++j) {
            r[i] += m[i * dim + j] * v[j];
        }
    }
}

static void matrix_vector_bench(benchmark::State &state) {
    std::size_t dim = 1 << state.range();
    float *mat = new float[dim * dim];
    float *vec = new float[dim];
    float *res = new float[dim];

    for (std::size_t i = 0; i < dim; ++i) {
        vec[i] = rand() % 100;
        res[i] = 0;
        for (std::size_t j = 0; j < dim; ++j) {
            mat[i * dim + j] = rand() % 100;
        }
    }

    for (auto _ : state) {
        matrix_vector(mat, vec, res, dim);
    }
    delete [] mat;
    delete [] vec;
    delete [] res;

    state.SetItemsProcessed(dim * dim * state.iterations());
    state.SetBytesProcessed(dim * (dim + 2) * state.iterations() * sizeof(float));
}

BENCHMARK(matrix_vector_bench)->DenseRange(8, 10)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
