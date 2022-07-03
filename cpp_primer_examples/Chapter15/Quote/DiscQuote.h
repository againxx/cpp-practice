#ifndef DISCQUOTE_H_
#define DISCQUOTE_H_

#include <string>
#include <utility>
#include "Quote.h"

class DiscQuote : public Quote {
public:
    DiscQuote() {
        std::cout << "DiscQuote: default constructor" << '\n';
    }

    DiscQuote(const DiscQuote& rhs) :
        Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) {
        std::cout << "DiscQuote: copy constructor" << '\n';
    }

    DiscQuote(DiscQuote&& rhs) :
        Quote(std::move(rhs)),
        min_qty(std::move(rhs.min_qty)),
        discount(std::move(rhs.discount)) {
        std::cout << "DiscQuote: move constructor" << '\n';
    }

    DiscQuote(const std::string& book, double p, std::size_t qty, double dis) :
        Quote(book, p), min_qty(qty), discount(dis) {
            std::cout << "DiscQuote: constructed with bookNo, price, min_qty and discount" << '\n';
        }

    ~DiscQuote() {
        std::cout << "DiscQuote: destructor" << '\n';
    }

    DiscQuote& operator=(const DiscQuote& rhs) {
        std::cout << "DiscQuote: copy assignment operator" << '\n';
        Quote::operator=(rhs);
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        return *this;
    }

    DiscQuote& operator=(DiscQuote&& rhs) {
        std::cout << "DiscQuote: move assignment operator" << '\n';
        min_qty = std::move(rhs.min_qty);
        discount = std::move(rhs.discount);
        Quote::operator=(std::move(rhs));
        return *this;
    }

    double netPrice(std::size_t n) const override = 0;

    void debug() const override {
        Quote::debug();
        std::cout << "min_qty: " << min_qty << " discount: "
                  << discount << '\n';
    }

protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

#endif  // DISCQUOTE_H_
