class WithoutDefault {
public:
    WithoutDefault() = delete;
    explicit WithoutDefault(int i) : value_(i) { }

private:
    int value_;
};

int main() {
    WithoutDefault* wd = new WithoutDefault[5];
    return 0;
}
