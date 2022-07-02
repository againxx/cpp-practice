#include <string>
#include <unordered_map>
#include <iostream>

int main() {
    std::string str;
    while (std::cin >> str) {
        for (std::size_t i = 0; i < str.size(); ++i) {
            if (str.find_first_of(str[i]) == str.find_last_of(str[i])) {
                std::cout << str[i] << '\n';
                break;
            }
            else if (i == str.size() - 1) {
                std::cout << -1 << '\n';
            }
        }
    }
}
