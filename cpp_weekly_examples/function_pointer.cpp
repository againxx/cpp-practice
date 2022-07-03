#include <iostream>
#include <string>

void HelloWorld(const std::string &str)
{
    std::cout << str << '\n';
}

int main()
{
    using MyFunc = void(*)(const std::string &);

    MyFunc func = HelloWorld;
    func("again");

    return 0;
}
