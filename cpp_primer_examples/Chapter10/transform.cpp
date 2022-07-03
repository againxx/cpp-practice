#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vi = {1, -2, 3, 6, 4};
    std::transform(vi.cbegin(), vi.cend(), vi.begin(),
            [](int i) -> int {
                if (i < 0)
                    return -i;
                else
                    return i; });
    for (auto& i : vi) {
        std::cout << i << '\n';
    }
    return 0;
}
