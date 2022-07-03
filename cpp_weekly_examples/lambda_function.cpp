#include <algorithm>
#include <iostream>
#include <set>
#include <functional>
#include <numeric>

template<typename T>
std::set<T> filter(const std::set<T>& input,
                   const std::function<bool(T)>& compare) {
    std::set<T> result;
    for (auto it = input.cbegin(); it != input.cend(); ++it) {
        if (compare(*it)) {
            result.insert(*it);
        }
    }
    return result;
}

int main() {
    std::set<int> test_set;
    for (std::size_t i = 0; i < 1000; ++i) {
        test_set.emplace(i);
    }

    std::set<int> result = filter<int>(test_set, [](int i){ return i % 2 == 0; });
    for (auto i : result) {
        std::cout << i << '\n';
    }
    return 0;
}
