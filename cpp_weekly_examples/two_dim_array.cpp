#include <array>

int main() {
    std::array<int, 10000> arr1{};
    // std::array<std::array<int, 100>, 100> arr2{};
    for (std::size_t i = 0; i < 100000; ++i) {
        // for (std::size_t j = 0; j < 10000; ++j) {
        // }
        for (std::size_t j = 0; j < 100; ++j) {
            for (std::size_t k = 0; k < 100; ++k) {
                // arr2[j][k] = arr2[j][k] ? 0 : 1;
                arr1[j * 100 + k] = arr1[j * 100 + k] ? 0 : 1;
            }
        }
    }
    return 0;
}
