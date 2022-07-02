#include <atomic>
#include <thread>
#include <chrono>
#include <iostream>
#include <semaphore>

std::atomic<int> counter{};
constexpr int count_limit = 1'000'000;
std::binary_semaphore singal2Ping(0);
std::binary_semaphore singal2Pong(0);

void ping() {
    while (counter < count_limit) {
        singal2Ping.acquire();
        ++counter;
        singal2Pong.release();
    }
}

void pong() {
    singal2Pong.acquire();
    singal2Ping.release();
}

int main() {
    singal2Ping.release();
    std::thread t1(ping);
    std::thread t2(pong);

    t1.join();
    t2.join();

    auto begin = std::chrono::system_clock::now();
    std::chrono::duration<double> last = std::chrono::system_clock::now() - begin;
    std::cout << last.count() << '\n';
    return 0;
}
