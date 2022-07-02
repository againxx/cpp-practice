#include <iostream>

template<typename T>
class AddSpace {
    const T& ref;
public:
    explicit AddSpace(const T& val) : ref(val) {};
    friend std::ostream& operator<<(std::ostream& os, AddSpace<T> as) {
        os << as.ref << ' ';
    }
};

template<typename... Types>
void print(Types... args) {
    (std::cout << ... << AddSpace(args)) << '\n';
}

int main() {
    print(1, 1.0, "abc");
    return 0;
}
