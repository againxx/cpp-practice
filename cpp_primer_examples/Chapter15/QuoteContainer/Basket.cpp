#include "Basket.h"

double printTotal(std::ostream &os, const Quote &item, std::size_t n);

double Basket::totalReceipt(std::ostream& os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin();
         iter != items.cend();
         iter = items.upper_bound(*iter)) {
        sum += printTotal(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}
