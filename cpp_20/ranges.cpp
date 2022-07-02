#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> inputs = {0, 1, 2, 3, 4, 5, 6};
    auto even = [](int i) { return i % 2 == 0; };
    auto square = [](int i) { return i * i; };
    for (auto i : inputs | std::views::filter(even) | std::views::transform(square))
        std::cout << i << '\n';

    return 0;
}
