#include <iostream>

#include "Quote.h"
#include "BulkQuote.h"

double printTotal(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.netPrice(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << std::endl;
    item.debug();
    return ret;
}

int main() {
    // Quote basic_quote("cpp primer", 10.0);
    // BulkQuote bulk_quote("csapp", 20.0, 2, 0.2);
    std::cout << "------ Quote Default Constructor ------" << '\n';
    Quote basic_quote1{};
    std::cout << "------ Quote Nondefault Constructor ------" << '\n';
    Quote basic_quote2("cpp primer", 10.0);
    std::cout << "------ BulkQuote Default Constructor ------" << '\n';
    BulkQuote bulk_quote1{};
    std::cout << "------ BulkQuote Nondefault Constructor ------" << '\n';
    BulkQuote bulk_quote2{"csapp", 20.0, 2, 0.2};
    std::cout << "------ Print Total ------" << '\n';
    printTotal(std::cout, basic_quote2, 3);
    printTotal(std::cout, bulk_quote2, 3);
    std::cout << "------ Quote Copy Assignment Operator ------" << '\n';
    basic_quote1 = basic_quote2;
    std::cout << "------ BulkQuote Copy Assignment Operator ------" << '\n';
    bulk_quote1 = bulk_quote2;
    std::cout << "------ BulkQuote Nondefault Constructor & Quote Move Assignment Operator ------" << '\n';
    basic_quote2 = BulkQuote{"effective c++", 10.0, 2, 0.15};
    std::cout << "------ BulkQuote Nondefault Constructor & BulkQuote Move Assignment Operator ------" << '\n';
    bulk_quote2 = BulkQuote{"effective c++", 10.0, 2, 0.15};
    std::cout << "------ Quote Copy Constructor ------" << '\n';
    Quote basic_quote3{bulk_quote2};
    std::cout << "------ BulkQuote Copy Constructor ------" << '\n';
    BulkQuote bulk_quote3{bulk_quote2};
    std::cout << "------ Quote Move Constructor ------" << '\n';
    Quote basic_quote4{BulkQuote{"effective c++", 10.0, 2, 0.15}};
    std::cout << "------ BulkQuote Move Constructor ------" << '\n';
    BulkQuote bulk_quote4{std::move(bulk_quote3)};
    std::cout << "------ Destructors ------" << '\n';
    return 0;
}
