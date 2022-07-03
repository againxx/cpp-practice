#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int val = 41;
    std::vector<int> vec = {1, 2, 3, 32, 10};
    int ia[] = {1, 3, 42, 11, 42};
    auto result = std::count(std::cbegin(ia), std::cend(ia), val);
    std::cout << result << '\n';
    // std::cout << "The value " << val
    //     << (result == std::cend(ia) ? " is not present" : " is present") << '\n';
    return 0;
}
