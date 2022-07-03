#include <array>
#include <iostream>

template<size_t N>
void printArr(std::array<int, N> arr) {
    std::cout << N << '\n';
    for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
        std::cout << *it << '\n';
    }
}

int main() {
    std::array<int, 5> a;
    printArr(a);
    return 0;
}
