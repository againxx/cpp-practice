#include <iostream>
#include "blob.hpp"

int main() {
    Blob articles = {"a", "an", "the"};
    std::cout << articles.back() << '\n';
    std::cout << articles.front() << '\n';
    return 0;
}
