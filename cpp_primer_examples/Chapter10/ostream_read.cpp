#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream ifs("string.txt");
    std::istream_iterator<std::string> is_iter(ifs), eof;
    std::vector<std::string> vec;
    std::copy(is_iter, eof, std::back_inserter(vec));
    std::cout << vec.size() << '\n';
    std::cout << vec[0] << '\n';
    std::cout << vec[1] << '\n';
    std::cout << vec[2] << '\n';
    std::cout << vec[3] << '\n';
    return 0;
}
