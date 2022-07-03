#include <cstddef>
#include <memory>

template<class T, std::size_t SIZE>
struct Array {
T* data();
const T* data() const { return std::addressof(data_[0]); }

constexpr std::size_t size() const { return SIZE; }
T* begin() { return data(); }
T* end() { return begin() + size(); }
T& operator[](std::size_t index) { return data_[index]; }

T data_[SIZE];
};

template<class T, std::size_t SIZE>
T* Array<T, SIZE>::data() {
    return const_cast<T*>(const_cast<const Array<T, SIZE>&>(*this).data());
}

int main() {
    Array<int, 3> a1{1, 2, 3};
    Array<double, 2> a2{2.0};
    return 0;
}
