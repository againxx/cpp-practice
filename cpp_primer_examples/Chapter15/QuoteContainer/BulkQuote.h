#ifndef BULKQUOTE_H_
#define BULKQUOTE_H_

#include <string>
#include "DiscQuote.h"

class BulkQuote : public DiscQuote {
public:
    using DiscQuote::DiscQuote;

    double netPrice(std::size_t n) const override;
};

#endif  // BULKQUOTE_H_
