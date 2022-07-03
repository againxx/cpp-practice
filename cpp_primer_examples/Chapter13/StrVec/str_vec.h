#ifndef STR_VEC_H_
#define STR_VEC_H_

#include <string>
#include <memory>
#include <utility>

class StrVec {
public:
    StrVec() = default;
    StrVec(const StrVec&);
    StrVec(StrVec &&s) noexcept;
    StrVec(std::initializer_list<std::string>);
    StrVec& operator=(const StrVec&);
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec();

    void push_back(const std::string&);
    void push_back(std::string&&);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }
    const std::string* cbegin() const { return elements; }
    const std::string* cend() const { return first_free; }
    void reserve(std::size_t);
    void shrink_to_fit();
    void resize(std::size_t);
    void resize(std::size_t, const std::string&);

    template<typename... Args>
    void emplace_back(Args&&...);

private:
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }

    static std::pair<std::string*, std::string*>
        alloc_n_copy(const std::string*, const std::string*);

    void free();
    void reallocate();

    static std::allocator<std::string> alloc;
    std::string *elements = nullptr;
    std::string *first_free = nullptr;
    std::string *cap = nullptr;
};

template<typename... Args>
inline void StrVec::emplace_back(Args&&... args) {
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif  // STR_VEC_H_
