#include <iostream>
#include "str_vec.h"

int main() {
    StrVec vec;
    std::string s1 = "some string or another";
    std::string s2 = "the end";
    vec.push_back(s1);
    vec.push_back("done");
    vec.emplace_back(10, 'c');
    vec.emplace_back(s1 + s2);
    for (const auto& str : vec) {
        std::cout << str << '\n';
    }
    return 0;
}
