#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main() {
    std::list<int> lst = {1, 2, 3, 4};
    std::list<int> lst2, lst3;
    std::copy(lst.cbegin(), lst.cend(), std::front_inserter(lst2));
    std::cout << "List 2:" << '\n';
    std::for_each(lst2.cbegin(), lst2.cend(),
            [](int i){ std::cout << i << ' '; });

    std::copy(lst.cbegin(), lst.cend(), std::inserter(lst3, lst3.begin()));
    std::cout << "\nList 3:" << '\n';
    std::for_each(lst3.cbegin(), lst3.cend(),
            [](int i){ std::cout << i << ' '; });
    return 0;
}
