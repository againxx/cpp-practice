#include <vector>
#include <iostream>
#include <iterator>
#include <numeric>

int main() {
    // std::istream_iterator<int> in_iter(std::cin);
    // std::istream_iterator<int> eof;
    std::vector<int> vec = {1, 2, 3, 4};
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::copy(vec.cbegin(), vec.cend(), out_iter);
    // while (in_iter != eof) {
    //     vec.push_back(*in_iter++);
    // }

    // int sum = std::accumulate(in_iter, eof, 0);
    // std::cout << sum << '\n';
    return 0;
}
