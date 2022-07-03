#include <chrono>
#include <iomanip>
#include <vector>
#include <iostream>
#include <numeric>
#include <utility>
#include <execution>

int main() {
    auto eval = [](auto fun) {
        const auto t1 = std::chrono::high_resolution_clock::now();
        const auto [name, result] = fun();
        const auto t2 = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double, std::milli> ms = t2 - t1;
        std::cout << std::fixed << std::setprecision(1) << name << " result "
                  << result << " took " << ms.count()
                  << "ms\n";
    };
    {
        const std::vector<double> v(100'000'007, 0.1);
        eval([&v]{return std::pair{"std::accumulate (double)",
                  std::accumulate(v.cbegin(), v.cend(), 0.0)};});
        eval([&v]{return std::pair{"std::reduce (seq, double)",
                  std::reduce(std::execution::seq, v.cbegin(), v.cend(), 0.0)};});
        eval([&v]{return std::pair{"std::reduce (par, double)",
                  std::reduce(std::execution::par, v.cbegin(), v.cend(), 0.0)};});
    }
    {
        const std::vector<long> v(100'000'007, 1);
        eval([&v]{return std::pair{"std::accumulate (long)",
                  std::accumulate(v.cbegin(), v.cend(), 0.0)};});
        eval([&v]{return std::pair{"std::reduce (seq, long)",
                  std::reduce(std::execution::seq, v.cbegin(), v.cend(), 0.0)};});
        eval([&v]{return std::pair{"std::reduce (par, long)",
                  std::reduce(std::execution::par, v.cbegin(), v.cend(), 0.0)};});
    }
    return 0;
}
