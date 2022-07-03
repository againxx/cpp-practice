#include <benchmark/benchmark.h>
// #include <cstdlib>
#include <new>
#include <iostream>
#include <immintrin.h>

float prod_8(float *m_v, float *v) {
    union {
        float r[8];
        __m256 rv;
    };
    rv = _mm256_dp_ps(_mm256_load_ps(m_v), _mm256_load_ps(v), 0xf1);
    return r[0] + r[4];
}

float vv_prod(float *m_v, float *v, std::size_t dim) {
    float res = 0;
    for (std::size_t i = 0; i < dim; i += 8) {
        res += prod_8(m_v + i, v + i);
    }
    return res;
}

void matrix_vector(float *m, float *v, float *r, std::size_t dim) {
    for (std::size_t i = 0; i < dim; ++i) {
        r[i] = vv_prod(&m[i * dim], v, dim);
    }
}

static void matrix_vector_bench(benchmark::State &state) {
    std::size_t dim = 1 << state.range();
    // float *mat = static_cast<float*>(std::aligned_alloc(64, dim * dim * sizeof(float)));
    // float *vec = static_cast<float*>(std::aligned_alloc(64, dim * sizeof(float)));
    float *mat = new (std::align_val_t(32)) float[dim * dim];
    float *vec = new (std::align_val_t(32)) float[dim];
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
    // std::free(mat);
    // std::free(vec);
    delete [] mat;
    delete [] vec;
    delete [] res;

    state.SetItemsProcessed(dim * dim * state.iterations());
    state.SetBytesProcessed(dim * (dim + 2) * state.iterations() * sizeof(float));
}

BENCHMARK(matrix_vector_bench)->DenseRange(8, 10)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
