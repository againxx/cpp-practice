#include <iostream>
#include <thread>

int main() {
    std::thread t0([]() { std::cout << "hello world" << '\n';});
    t0.join();
    return 0;
}
