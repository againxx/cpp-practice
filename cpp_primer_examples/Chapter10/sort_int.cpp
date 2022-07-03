#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

int main() {
    std::istream_iterator<int> is_iter(std::cin), eof;
    std::vector<int> ivec;
    std::copy(is_iter, eof, std::back_inserter(ivec));
    std::sort(ivec.begin(), ivec.end());
    std::unique_copy(ivec.cbegin(), ivec.cend(),
            std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
