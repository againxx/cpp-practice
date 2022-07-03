#include <sstream>
#include <string>

template<typename T>
std::string debug_rep(const T& t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

int main() {
    std::string s("hi");
    debug_rep(&s);
    return 0;
}
