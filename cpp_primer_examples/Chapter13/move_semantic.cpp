#include <iostream>
#include <vector>
#include <numeric>

void sumVector(const std::vector<int>& vec) {
    std::cout << "lvalue" << '\n';
    auto result = std::accumulate(vec.cbegin(), vec.cend(), 0);
    std::cout << result << '\n';
}

void sumVector(std::vector<int>&& vec) {
    std::cout << "rvalue" << '\n';
    auto result = std::accumulate(vec.cbegin(), vec.cend(), 0);
    std::cout << result << '\n';
}

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    sumVector(std::move(vec1));
    vec1 = std::vector<int>{2, 3, 4};
    return 0;
}
