#include <iostream>
#include <string>
#include "debug_rep.h"

template<typename T>
std::ostream &print(std::ostream &os, const T& t) {
    return os << t;
}

template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T& t, const Args&... rest) {
    os << t << ", ";
    return print(os, rest...);
}

template<typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest) {
    return print(os, debug_rep(rest)...);
}

int main() {
    int i = 42;
    double d = 3.14;
    float f = 2.0;
    std::string s = "hi";
    errorMsg(std::cout, i, d, &f, s, "ok");
    return 0;
}
