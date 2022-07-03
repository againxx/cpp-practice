#include <iostream>
#include <future>
#include <thread>

int main() {
    std::packaged_task<int()> task([]{ return 7; });
    std::future<int> result = task.get_future();
    std::thread(std::move(task)).detach();
    std::cout << "Waiting..." << '\n';
    result.wait();
    std::cout << "done!\n" << "future result is: " << result.get() << '\n';
    return 0;
}
