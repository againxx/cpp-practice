#include <type_traits>
#include <iostream>
#include <iomanip>

template<typename T>
struct is_object : std::integral_constant<bool,
    std::is_scalar<T>::value ||
    std::is_array<T>::value ||
    std::is_union<T>::value ||
    std::is_class<T>::value> {};

template<typename T>
constexpr bool is_object_v = is_object<T>::value;

int main() {
    int a[4];
    auto l = [] {return 1;};
    std::cout << std::boolalpha;
    std::cout << is_object_v<decltype(l)> << '\n';
    return 0;
}
