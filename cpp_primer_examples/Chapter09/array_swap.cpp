#include <iostream>
#include <array>
#include <iterator>

class Obj {
public:
    Obj(int id) : id_(id) { }

    Obj& operator=(const Obj& rhs) {
        std::cout << "Copy assignment" << id_ << '\n';
        return *this;
    }

    Obj& swap(const Obj& rhs) {
        std::cout << "Swap" << '\n';
        return *this;
    }

    int id_ = 0;
};

int main() {
    // std::array<int, 5> arr1{1, 2, 3, 4, 5};
    // std::array<int, 5> arr2{6, 7, 8, 9, 10};

    // auto cit = std::cbegin(arr1);
    // for (int i = 0; i < 5; ++i) {
    //     std::cout << *cit++ << '\n';
    //     if (i == 2) {
    //         std::swap(arr1, arr2);
    //     }
    // }
    std::array<Obj, 5> arr1{1, 2, 3, 4, 5};
    std::array<Obj, 5> arr2{6, 7, 8, 9, 10};

    std::swap(arr1, arr2);

    return 0;
}
