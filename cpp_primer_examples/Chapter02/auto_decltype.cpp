#include <iostream>
#include <typeinfo>
#include <type_traits>

decltype(auto) increment(int& a) {
    a++;
    return a;
}

int main() {
    int a = 3;
    auto c1 = a;
    decltype(a) c2 = a;
    decltype((a)) c3 = a;

    const int d = 5;
    auto f1 = d;
    decltype(d) f2 = d;

    std::cout << typeid(c1).name() << '\n';  // int
    std::cout << typeid(c2).name() << '\n';  // int
    std::cout << typeid(c3).name() << '\n';  // int&
    std::cout << typeid(f1).name() << '\n';  // int
    std::cout << typeid(f2).name() << '\n';  // const int

    c1++;
    c2++;
    c3++;
    f1++;

    std::cout << a << " " <<  c1 << " " << c2 << " " << c3 << " " << f1 << " " << f2 << '\n';

    int& p = increment(a);
    std::cout << p << '\n';

    auto ll = 10L;
    auto& e1 = 42;

    return 0;
}
