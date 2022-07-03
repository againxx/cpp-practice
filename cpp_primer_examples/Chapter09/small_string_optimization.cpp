#include <iostream>
#include <string>

int main() {
    int a = 1;
    auto b = new int(5);
    std::string str1 = "hello";
    std::string str2 = "hello world 1234";
    std::string str3('a', 5);
    std::cout << &a << '\n';
    std::cout << static_cast<void*>(str1.data()) << '\n';
    std::cout << b << '\n';
    std::cout << static_cast<void*>(str2.data()) << '\n';
    std::cout << static_cast<void*>(str3.data()) << '\n';
    delete b;
    return 0;
}
