#include <utility>
#include "BulkQuote.h"

BulkQuote::BulkQuote() {
    std::cout << "BulkQuote: default constructor" << '\n';
}

BulkQuote::BulkQuote(const BulkQuote& rhs) : DiscQuote(rhs) {
    std::cout << "BulkQuote: copy constructor" << '\n';
}

BulkQuote::BulkQuote(BulkQuote&& rhs) : DiscQuote(std::move(rhs)) {
    std::cout << "BulkQuote: move constructor" << '\n';
}

BulkQuote::~BulkQuote() {
    std::cout << "BulkQuote: destructor" << '\n';
}

BulkQuote& BulkQuote::operator=(const BulkQuote& rhs) {
    std::cout << "BulkQuote: copy assignment operator" << '\n';
    DiscQuote::operator=(rhs);
    return *this;
}

BulkQuote& BulkQuote::operator=(BulkQuote&& rhs) {
    std::cout << "BulkQuote: move assignment operator" << '\n';
    DiscQuote::operator=(std::move(rhs));
    return *this;
}

double BulkQuote::netPrice(std::size_t n) const {
    if (n >= min_qty)
        return n * (1 - discount) * price;
    return n * price;
}
