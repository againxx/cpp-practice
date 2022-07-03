#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

class TestFunc
{
public:
    template<typename T>
    void operator()(T arg)
    {
        arg[0] = 'H';
        std::cout << arg << '\n';
    }
};

void print(std::function<void (const std::string&)> func)
{
    func("hello world");
}

int main()
{
    /* std::vector<int> vec = {1,5,4,3,2}; */
    /* std::vector<int>::const_iterator it = std::find_if(vec.cbegin(), vec.cend(), [](int a){ return a > 3; }); */
    /* std::cout << *it << '\n'; */
    /* print([](auto str){ std::cout << str << '\n'; }); */
    auto lambda_func = [](const auto& arg){
        std::cout << arg << '\n';
    };
    std::function<void(const std::string&)> std_func = lambda_func;
    /* TestFunc test_func; */
    std::string s = "abc";
    /* test_func(s); */
    lambda_func(s);
    std::cout << s << '\n';
    /* std_func(s); */
    return 0;
}
