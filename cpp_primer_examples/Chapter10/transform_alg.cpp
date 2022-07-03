#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    std::vector<float> f_vec = {1.2, 2.1, 3.8};
    std::vector<std::uint16_t> s_vec(3);

    std::transform(f_vec.cbegin(), f_vec.cend(), s_vec.begin(),
            [](float f){ return f * 1000; });
    for (auto& s : s_vec)
    {
        std::cout << s << '\n';
    }
    return 0;
}
