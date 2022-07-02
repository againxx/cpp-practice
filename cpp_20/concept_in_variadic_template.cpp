#include <iostream>
#include <type_traits>

template<typename T>
concept Arithmatic = std::is_arithmetic<T>::value;

template<Arithmatic... Args>
bool all(Args... args) { return (... && args);  }

template<Arithmatic... Args>
bool any(Args... args) { return (... || args);  }

template<Arithmatic... Args>
bool none(Args... args) { return !(... || args);  }

int main() {
    std::cout << std::boolalpha << std::endl;
    std::cout << all(true, 1, 5, 5.5, false) << '\n';
    std::cout << any(true, 1, 5, 5.5, false) << '\n';
    std::cout << none(true, 1, 5, 5.5, false) << '\n';
    return 0;
}
