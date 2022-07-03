#include <iostream>
#include "message.h"
#include "folder.h"

int main() {
    Message m1("hello");
    Message m2("world");
    Folder f1("1");
    m1.save(f1);
    Folder f2("2");
    m2.save(f2);
    std::cout << "Folder 1:" << '\n';
    f1.printMsg();
    std::cout << "Folder 2:" << '\n';
    f2.printMsg();

    Message m3(m2);
    std::cout << "Copy message 3:" << '\n';
    f2.printMsg();
    m3 = Message("here");
    m3.save(f2);
    std::cout << "Change message 3:" << '\n';
    f2.printMsg();

    m1 = m3;
    std::cout << "Now folder 1:" << '\n';
    f1.printMsg();
    std::cout << "Now folder 2:" << '\n';
    f2.printMsg();
    return 0;
}
