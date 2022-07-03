#include <iostream>
#include <string>

template<typename ...Param>
std::vector<std::string> to_string(const Param& ...param ) {

}

int main() {
    auto vec = to_string(1, 5.3, "hello");

    for (const auto& i : vec) {
        std::cout << i << '\n';
    }
    return 0;
}
