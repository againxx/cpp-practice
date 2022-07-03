#ifndef QUOTE_H_
#define QUOTE_H_

#include <iostream>
#include <string>
#include <utility>

class Quote {
public:
    Quote(const std::string &book, double p) : bookNo(book), price(p) {}

    virtual ~Quote() {}

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
