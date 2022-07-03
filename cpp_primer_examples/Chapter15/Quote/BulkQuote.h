#ifndef BULKQUOTE_H_
#define BULKQUOTE_H_

#include <string>
#include "DiscQuote.h"

class BulkQuote : public DiscQuote {
public:
    BulkQuote();
    BulkQuote(const BulkQuote& rhs);
    BulkQuote(BulkQuote&& rhs);

    using DiscQuote::DiscQuote;

    // BulkQuote(const std::string& book, double p, std::size_t qty, double dis) :
    //     DiscQuote(book, p, qty, dis) {
    //     std::cout << "BulkQuote: constructed with bookNo, price, min_qty and discount" << '\n';
    // }

    ~BulkQuote();

    BulkQuote& operator=(const BulkQuote& rhs);
    BulkQuote& operator=(BulkQuote&& rhs);

    double netPrice(std::size_t n) const override;
};

#endif  // BULKQUOTE_H_
