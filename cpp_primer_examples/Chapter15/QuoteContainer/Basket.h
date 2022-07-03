#ifndef BASKET_H_
#define BASKET_H_

#include <set>
#include <memory>
#include "Quote.h"

class Basket {
public:
    void addItem(const Quote& sale) { items.insert(sale); }
    void addItem(Quote&& sale) { items.insert(sale); }

    double totalReceipt(std::ostream&) const;

private:
    static bool compare(const std::shared_ptr<Quote>& lhs,
                        const std::shared_ptr<Quote>& rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif  // BASKET_H_
