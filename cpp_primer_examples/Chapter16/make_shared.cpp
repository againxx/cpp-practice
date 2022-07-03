#include <iostream>
#include <utility>
#include <memory>
#include <string>

template<typename T, typename... Args>
auto my_make_shared(Args&&... args) {
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {
    auto p = my_make_shared<std::string>(std::string("hello"));
    std::cout << *p << '\n';
    return 0;
}
