#include <iostream>
#include <vector>
#include <numeric>
#include <memory>

#include "Quote.h"
#include "BulkQuote.h"
#include "Basket.h"

double printTotal(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.netPrice(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << std::endl;
    // item.debug();
    return ret;
}

int main() {
    Basket basket;
    for (std::size_t i = 0; i < 15; ++i) {
        basket.addItem(std::make_shared<Quote>("0-201-83470-1", 50));
        basket.addItem(std::make_shared<BulkQuote>("0-201-54848-8", 50, 10, 0.25));
    }
    basket.totalReceipt(std::cout);
    return 0;
}
