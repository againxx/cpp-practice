#include <iostream>
#include <string>

class Str {
public:
    explicit Str(const char* c) : s(c) {}

    Str(const Str& other) :
        s(other.s) {
        std::cout << "Copy Construction" << '\n';
    }

    Str(Str&& other) noexcept :
        s(std::move(other.s)) {
        std::cout << "Move Construction" << '\n';
    }
private:
    std::string s;
};

void print(Str str) {
    Str own_str = std::move(str);
}

int main() {
    print(Str("hello"));
    return 0;
}
