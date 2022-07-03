#include <iostream>
#include <stdexcept>

class Obj
{
public:
    explicit Obj(int i) : val(i)
    {
        std::cout << "Constructor" << val << '\n';
    }
    ~Obj()
    {
        std::cout << "Destructor" << val << '\n';
    }
private:
    int val;
};

void foo()
{
    Obj obj(2);
    throw std::runtime_error("Oh no");
}

void bar()
{
    Obj obj(1);
    foo();
}

int main()
{
    try
    {
        bar();
    }
    catch (std::runtime_error err)
    {
        std::cout << err.what() << '\n';
    }
    return 0;
}
