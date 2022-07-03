#include <utility>
#include "BulkQuote.h"

double BulkQuote::netPrice(std::size_t n) const {
    if (n >= min_qty)
        return n * (1 - discount) * price;
    return n * price;
}
