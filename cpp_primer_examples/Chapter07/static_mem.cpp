#include <array>
#include <vector>
#include <iostream>

class StaticMem
{
public:
    StaticMem() = default;
    ~StaticMem() = default;

    void test() const;

public:
    static int size;
    int other_size;
};

void StaticMem::test() const
{
    size = 6;
    other_size = 1;
}

int StaticMem::size = 5;

int main()
{
    StaticMem s;
    std::cout << StaticMem::size << '\n';
    s.test();
    std::cout << StaticMem::size << '\n';
    return 0;
}
