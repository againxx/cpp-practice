#include <iostream>
#include "folder.h"
#include "message.h"

Folder::~Folder() {
    for (auto it = messages.begin(); it != messages.end();)
        (*it++)->remove(*this);
}

void Folder::printMsg() const {
    for (auto m : messages)
        std::cout << m->contents << '\n';
}
