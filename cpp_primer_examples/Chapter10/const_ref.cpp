#include <iostream>

class Test {
public:
    explicit Test(int &i) :
        ref_i(i) { }
    void incrementI() const {
        ++ref_i;
    }

private:
    int &ref_i;
};

int main() {
    int i = 42;
    Test test(i);
    test.incrementI();
    std::cout << i << '\n';
    return 0;
}
