#include <iterator>
#include <numeric>

template<typename Iterator, typename T>
struct accumulate_block
{
    void operator() (Iterator first, Iterator second, T& result) const {
        result = std::accumulate(first, second);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
    const unsigned long length = std::distance(first, last);
    if (!length)
        return init;
}
