#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)];
    auto ret = std::copy(std::cbegin(a1), std::cend(a1), a2);
    std::cout << a2 << '\n';
    std::cout << ret << '\n';
    return 0;
}
