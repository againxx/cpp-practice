#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main() {
    std::list<int> ilst = {3, 4, 5};
    std::vector<int> ivec;
    std::replace_copy(ilst.begin(), ilst.end(),
            std::back_inserter(ivec), 4, 42);
    for (auto& i : ivec) {
        std::cout << i << '\n';
    }
    // std::cout << ilst.size() << '\n';
    return 0;
}
