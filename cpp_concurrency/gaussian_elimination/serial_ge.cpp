#include <vector>

void serial_ge(std::vector<double>& matrix, std::size_t dim) {
    for (std::size_t i = 0; i < dim - 1; ++i) {
        // Normalization
        for (std::size_t j = i + 1; j < dim; ++j) {
            matrix[i * dim + j] /= matrix[i * dim + i];
        }
        matrix[i * dim + i] = 1.0;

        // Elimination
        for (std::size_t j = i + 1; j < dim; ++j) {
            double scale = matrix[j * dim + i];
            for (std::size_t k = i + 1; k < dim; ++k) {
                matrix[j * dim + k] -= matrix[i * dim + k];
            }
            matrix[j * dim + i] = 0.0;
        }
    }
}
