#include <thread>
#include <atomic>
#include <benchmark/benchmark.h>

class SpinLock {
    std::atomic_bool flag;
public:
    SpinLock() : flag(false) {};
    void lock() {
        while (flag.exchange(true))
            ;
    }
    void unlock() {
        flag.store(false);
    }
};

static void test_spinlock(benchmark::State& s) {
    auto num_of_threads = s.range(0);
    SpinLock l;
    std::vector<std::thread> threads;
    threads.reserve(num_of_threads);

    for (auto _ : s) {
        unsigned counter = 0u;
        auto func = [&] {
            for (auto i = 0u; i < 100000; ++i) {
                l.lock();
                ++counter;
                l.unlock();
            }
        };
        for (unsigned t = 0; t < num_of_threads; ++t) {
            threads.emplace_back(func);
        }
        for (auto& t : threads) {
            t.join();
        }
        threads.clear();
    }
}

BENCHMARK(test_spinlock)->Range(1, std::thread::hardware_concurrency())->RangeMultiplier(2)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
