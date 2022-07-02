#include <iostream>
#include <type_traits>
#include <vector>

template<typename T>
concept Integral = std::is_integral_v<T>;

Integral auto getIntegral(int val) {
    return val;
}

int main() {
    std::cout << std::boolalpha << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    for (Integral auto i : vec) std::cout << i << " ";

    Integral auto b = 5.5;
    std::cout << b << '\n';

    Integral auto integ = getIntegral(10);
    std::cout << integ << '\n';

    auto integ1 = getIntegral(10);
    std::cout << integ1 << '\n';

    std::cout << std::endl;

    return 0;
}
