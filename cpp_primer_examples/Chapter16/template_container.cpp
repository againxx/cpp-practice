#include <iostream>
#include <vector>
#include <array>
#include <string>

template<typename T>
void print_container(const T& container) {
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        std::cout << *it << '\n';
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    std::array<std::string, 2> arr = {"here", "there"};
    print_container(vec);
    print_container(arr);
    return 0;
}
