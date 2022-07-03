#include <string>
#include <iostream>

const std::string& shorterString(const std::string& str1,
                                 const std::string& str2) {
    std::cout << "const version" << '\n';
    return str1.length() < str2.length() ? str1 : str2;
}

std::string& shorterString(std::string& str1, std::string& str2) {
    std::cout << "non-const version" << '\n';
    return const_cast<std::string&>(shorterString(
                static_cast<const std::string&>(str1),
                static_cast<const std::string&>(str2)));
}

int main() {
    std::string s1 = "abcdef";
    std::string s2 = "hello";
    std::cout << shorterString(s1, s2) << '\n';
    return 0;
}
