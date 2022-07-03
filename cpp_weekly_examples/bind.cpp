#include <functional>
#include <iostream>
#include <string>
#include <sstream>

std::string toString(int a, int b, int c) {
    std::ostringstream oss;
    oss << a << ',' << b << ',' << c;
    return oss.str();
}

int main() {
    using namespace std::placeholders;
    // auto func1 = std::bind<std::string>(toString, _1, _2, 5);
    auto func2 = [](int a, int b) { return toString(a, b, 5); };
    for (std::size_t i = 0; i < 10000000; ++i) {
        auto s2 = func2(1, 2);
    }
    // auto s2 = func2(1, 2);
    // std::cout << s1 << '\n';
    // std::cout << s2 << '\n';
}
