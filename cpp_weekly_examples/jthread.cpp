#include <iostream>
#include <thread>

int main() {
    std::jthread t0([]() { std::cout << "hello world" << '\n';});
    return 0;
}
