#include <iostream>

template<unsigned n>
struct factorial
{
    static constexpr unsigned value = n * factorial<n - 1>::value;
};

template<>
struct factorial<0>
{
    static constexpr unsigned value = 1;
};

int main() {
    std::cout << factorial<6>::value << '\n';
    return 0;
}
