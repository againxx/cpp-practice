#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<std::vector<int>> vec;
    vec.reserve(5);
    std::fill_n(std::back_inserter(vec), 5, std::vector<int>(4, 1));

    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::for_each(vec.cbegin(), vec.cend(),
            [&out_iter](const auto& inner_vec) {
                std::copy(inner_vec.cbegin(), inner_vec.cend(), out_iter);
                std::cout << '\n';
            });
    return 0;
}
