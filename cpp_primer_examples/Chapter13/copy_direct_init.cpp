#include <iostream>

class MyClass
{
public:
    MyClass(int val) : data(val)
    {
        std::cout << "Direct constructor!" << '\n';
    }

    MyClass(const MyClass& other) : data(other.data)
    {
        std::cout << "Copy constructor!" << '\n';
    }

    int data = 0;
};

void f(MyClass c)
{
    std::cout << "In function" << '\n';
}

int main(int argc, char *argv[])
{
    std::cout << "c1 init" << '\n';
    MyClass c1(5);
    std::cout << "c2 init" << '\n';
    MyClass c2(c1);
    std::cout << "c3 init" << '\n';
    MyClass c3 = c1;
    std::cout << "c4 init" << '\n';
    MyClass c4 = 10;
    f(c4);
    return 0;
}
