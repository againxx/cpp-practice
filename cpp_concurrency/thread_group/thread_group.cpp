#include <iostream>
#include <algorithm>
#include <vector>
#include <concepts>
#include <thread>
#include <atomic>
#include <ranges>

namespace stdv = std::views;
namespace stdr = std::ranges;

struct ThreadGroup {
    ThreadGroup(std::uint64_t n, std::invocable<std::stop_token> auto&& f) {
        for (auto i : stdv::iota(0u, n)) members.emplace_back(f);
    }
    void request_stop() {
        stdr::for_each(members, [](std::jthread& t){ t.request_stop(); });
    }

private:
    std::vector<std::jthread> members;
};

int main() {
    std::atomic<std::uint64_t> count(0);
    {
        ThreadGroup tg(6, [&](std::stop_token st) {
            while (!st.stop_requested()) {
                ++count;
            }
        });

        tg.request_stop();
    }
    std::cout << count << '\n';
    return 0;
}
