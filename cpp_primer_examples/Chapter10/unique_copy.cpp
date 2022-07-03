#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <iterator>

int main() {
    std::vector<int> vec = {1, 1, 2, 3, 3, 1};
    std::list<int> lst;
    std::unique_copy(vec.cbegin(), vec.cend(), std::back_inserter(lst));
    for (auto i : lst)
        std::cout << i << '\n';
    return 0;
}
