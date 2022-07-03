#ifndef QUOTE_H_
#define QUOTE_H_

#include <iostream>
#include <string>
#include <utility>

class Quote {
public:
    Quote() {
        std::cout << "Quote: default constructor" << '\n';
    }

    Quote(const Quote& rhs) : bookNo(rhs.bookNo), price(rhs.price) {
        std::cout << "Quote: copy constructor" << '\n';
    }

    Quote(Quote&& rhs) :
        bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {
        std::cout << "Quote: move constructor" << '\n';
    }

    Quote(const std::string &book, double p) : bookNo(book), price(p) {
        std::cout << "Quote: constructed with bookNo and price" << '\n';
    }

    Quote& operator=(const Quote& rhs) {
        std::cout << "Quote: copy assignment operator" << '\n';
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }

    Quote& operator=(Quote&& rhs) {
        std::cout << "Quote: move assignment operator" << '\n';
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);
        return *this;
    }

    virtual ~Quote() {
        std::cout << "Quote: destructor" << '\n';
    }

    std::string isbn() const { return bookNo; }

    virtual double netPrice(std::size_t n) const {
        return n * price;
    }

    virtual void debug() const {
        std::cout << "bookNo: " << bookNo << " price: " << price << '\n';
    }

private:
    std::string bookNo;
protected:
    double price = 0.0;
};

#endif  // QUOTE_H_
