#include <iostream>
#include <string>

int main() {
    std::string str1 = "hello  123456789";
    std::string str2 = "world  987654321";
    auto cit = str1.cbegin();
    for (std::size_t i = 0; i < 16; ++i) {
        std::cout << *cit++ << ' ';
        if (i == 5)
            std::swap(str1, str2);
    }
    return 0;
}
