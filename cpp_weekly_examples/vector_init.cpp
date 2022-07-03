#include <iostream>
#include <string>
#include <vector>

class MyClass
{
public:
    int size = 3;
    std::vector<std::string> v{size};
};

int main()
{
    MyClass mc;
    std::cout << mc.v.size() << '\n';
    std::cout << sizeof(int) << '\n';
    std::cout << sizeof(long unsigned int) << '\n';
    return 0;
}
