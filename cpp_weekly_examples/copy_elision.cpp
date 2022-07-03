struct S
{
    int data[6];
};

S func()
{
    S s{};
    return s;
}

int main()
{
    auto a = func();
    return 0;
}
