#include "str_vec.h"

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec &s) {
    auto new_data = alloc_n_copy(s.cbegin(), s.cend());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::StrVec(std::initializer_list<std::string> il) {
    elements = first_free = alloc.allocate(il.size());
    for (auto& s : il) {
        alloc.construct(first_free++, s);
    }
    cap = first_free;
}

StrVec::StrVec(StrVec &&s) noexcept :
    elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.cbegin(), rhs.cend());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

void StrVec::push_back(const std::string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string&& s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

void StrVec::resize(std::size_t new_size) {

}

void StrVec::resize(std::size_t new_size, const std::string &init_str) {

}

void StrVec::reserve(std::size_t new_capacity) {

}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, capacity());
    }
}

void StrVec::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(new_capacity);

    auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
                                        std::make_move_iterator(end()),
                                        first);
    free();
    elements = first;
    first_free = last;
    cap = elements + new_capacity;
}
