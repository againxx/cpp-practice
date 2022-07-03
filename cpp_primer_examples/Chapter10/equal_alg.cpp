#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {1, 2, 3};

    bool is_equal = std::equal(vec1.cbegin(), vec1.cend(), vec2.cbegin());
    std::cout << is_equal << '\n';
    return 0;
}
