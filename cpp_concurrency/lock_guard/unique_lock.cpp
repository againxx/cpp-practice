#include <iostream>
#include <thread>
#include <mutex>

int v = 1;

void critical_section(int change_v) {
    static std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);
    v = change_v;
    std::cout << v << '\n';
    lock.unlock();

    lock.lock();
    v += 1;
    std::cout << v << '\n';
}

int main() {
    std::thread t1{critical_section, 2};
    std::thread t2{critical_section, 3};
    t1.join();
    t2.join();
    return 0;
}
