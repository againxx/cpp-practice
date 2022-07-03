#include <iostream>
#include <string>
#include <memory>

int main() {
    int n = 5;
    std::allocator<std::string> allocator;
    std::string* const p = allocator.allocate(n);
    std::string* q = p;

    std::string s;
    while (std::cin >> s && q != p + n) {
        std::allocator_traits<std::allocator<std::string>>::construct(allocator, q++, s);
    }

    std::string* q2 = p;
    while (q2 != q) {
        std::cout << *q2++ << '\n';
    }

    while (q != p) {
        std::allocator_traits<std::allocator<std::string>>::destroy(allocator, --q);
    }
    return 0;
}
