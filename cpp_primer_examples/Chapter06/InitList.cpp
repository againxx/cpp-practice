#include <iostream>
#include <string>
#include <initializer_list>

void error_msg(std::string begin_msg, std::initializer_list<std::string> il, int error_code)
{
    std::cout << begin_msg << std::endl;
    std::cout << error_code << std::endl;
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        std::cout << *beg << " ";
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    error_msg("init", {"hello", "world", "test"}, 2);
    return 0;
}
