#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{6, 7, 8, 9};

    auto cit = std::cbegin(vec1);
    for (int i = 0; i < 5; ++i) {
        std::cout << *cit++ << '\n';
        if (i == 2) {
            std::swap(vec1, vec2);
        }
    }

    if (cit == std::cend(vec2))
        std::cout << "Point to another vector" << '\n';

    std::cout << vec1.size() << '\n';
    std::cout << vec2.size() << '\n';

    return 0;
}
