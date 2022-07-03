#include <time.h>
#include <cstdlib>
#include <stdio.h>

long absdiff(long x, long y) {
    long result;
    if (x > y)
        result = x - y;
    else
        result = y - x;
    return result;
}

int main() {
    std::size_t loop_count = 2 << 20;
    volatile long abs_value;
    for (std::size_t i = 0; i < loop_count; ++i) {
        abs_value = absdiff(rand() % 100, rand() % 100);
    }
}
