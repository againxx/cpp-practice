#include <iostream>
#include <iterator>
#include <memory>

int main()
{
    auto uni_ptr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; ++i)
    {
        std::cout << uni_ptr[i] << '\n';
    }
    return 0;
}
