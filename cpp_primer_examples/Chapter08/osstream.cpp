#include <iostream>
#include <ostream>
#include <sstream>

int main()
{
    std::ostringstream oss;
    oss << "hello " << 1 << " wolrd";
    std::cout << oss.str() << '\n';

    oss.clear();
    oss.str("");
    oss << "hello " << 2 << " wolrd";
    std::cout << oss.str() << '\n';
    return 0;
}
