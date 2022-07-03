#include <iostream>
#include <thread>
#include <chrono>
#include <future>

int main() {
    auto sleep_and_return = []{
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        return 0;
    };
    std::packaged_task<int()> task(sleep_and_return);
    std::future<int> f1 = task.get_future();
    std::thread(std::move(task)).detach();

    std::future<int> f2 = std::async(sleep_and_return);

    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread([&](std::promise<int> p){
        sleep_and_return();
        p.set_value(2);
    }, std::move(p)).detach();

    std::cout << "Waiting..." << '\n';
    f1.wait();
    f2.wait();
    f3.wait();
    std::cout << "Done\nResults are: " << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';

    {
        std::future<int> tmp = std::async(std::launch::async, []{
                std::chrono::milliseconds dura(5000);
                std::this_thread::sleep_for(dura);
                return 0;
        });
        // block here for VERY_LONG_TIME
    }
    std::cout << "Block or not?" << '\n';
    return 0;
}
