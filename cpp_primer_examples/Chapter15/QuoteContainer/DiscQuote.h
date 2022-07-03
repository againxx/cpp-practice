#ifndef DISCQUOTE_H_
#define DISCQUOTE_H_

#include <string>
#include <utility>
#include "Quote.h"

class DiscQuote : public Quote {
public:
    DiscQuote(const std::string& book, double p, std::size_t qty, double dis) :
        Quote(book, p), min_qty(qty), discount(dis) {}

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
