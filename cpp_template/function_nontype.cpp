#include <iostream>
#include <type_traits>
#include <utility>

int sum(int a, int b, double c) {
    return a + b + c;
}

int sum2(int a, int b, double c, float d) {
    return a + b + c + d;
}

template<typename F, F f, typename... Args>
int test(Args&&... args) {
    return f(std::forward<Args>(args)...);
}

int main() {
    auto res = test<decltype(&sum), sum>(1, 2, 3.0);
    std::cout << res << '\n';
    res = test<decltype(&sum2), sum2>(1, 2, 3.0, -3.0f);
    std::cout << res << '\n';
    return 0;
}
