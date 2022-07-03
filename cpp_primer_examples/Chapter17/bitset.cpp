#include <bitset>
#include <iostream>

int main() {
    std::bitset<32> bitvec(1010101);
    std::cout << std::hex << 1010101 << '\n';
    std::cout << bitvec << '\n';
    std::bitset<8> bitvec8;
    std::cin >> bitvec8;
    std::cout << bitvec8;
    return 0;
}
