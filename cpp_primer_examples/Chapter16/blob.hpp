#include <vector>
#include <memory>
#include <stdexcept>

template<typename T> class Blob {
public:
    using value_type = T;
    using size_type = typename std::vector<T>::size_type;

    Blob();
    Blob(std::initializer_list<T> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T& t) { data->push_back(t); }
    void push_back(T&& t) { data->push_back(t); }
    void pop_back();

    T& back();
    const T& back() const;
    T& front();
    const T& front() const;
    T& operator[](size_type i);
    const T& operator[](size_type i) const;

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string& msg) const;
};

template<typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) { }

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) { }

template<typename T>
void Blob<T>::check(size_type i, const std::string& msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::back() {
    return const_cast<T&>(const_cast<const Blob<T>&>(*this).back());
}

template<typename T>
const T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
const T& Blob<T>::front() const {
    check(0, "front on empty Blob");
    return data->front();
}

template<typename T>
T& Blob<T>::front() {
    return const_cast<T&>(const_cast<const Blob<T>&>(*this).front());
}

template<typename T>
T& Blob<T>::operator[](size_type i) {
    return const_cast<T&>(const_cast<const Blob<T>&>(*this)[i]);
}

template<typename T>
const T& Blob<T>::operator[](size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}
