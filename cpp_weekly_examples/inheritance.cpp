#include <iostream>

struct Base
{
    virtual void do_thing() = 0;
    virtual ~Base() = default;
    Base() = default;
    Base(const Base&) = default;
    Base(Base&&) = default;
    Base& operator=(const Base&) = default;
    Base& operator=(Base&&) = default;
    int data{};
};

struct Derived : Base
{
    void do_thing() override {}
};

int main()
{
    Base *b = new Derived();
    delete b;
    std::cout << "+abc" << std::endl;
    return 0;
}
