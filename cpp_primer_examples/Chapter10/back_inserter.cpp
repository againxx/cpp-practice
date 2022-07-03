#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec;
    auto it = std::back_inserter(vec);
    *it = 42;
    std::cout << vec.size() << '\n';
    std::cout << vec.back() << '\n';

    std::fill_n(it, 10, 0);
    std::cout << vec.size() << '\n';
    std::cout << vec.back() << '\n';
    ++it;
    *it = 5;
    std::cout << vec.size() << '\n';
    std::cout << vec.back() << '\n';
    return 0;
}
