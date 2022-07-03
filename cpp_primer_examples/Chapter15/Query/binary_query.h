#ifndef BINARY_QUERY_H_
#define BINARY_QUERY_H_

#include "query_base.h"
#include "query.h"

class BinaryQuery : public QueryBase {
protected:
    BinaryQuery(const Query& lhs, const Query& rhs, std::string s) :
        lhs_(lhs), rhs_(rhs), op_sym_(std::move(s)) { }

    std::string rep() const override {
        std::cout << "BinaryQuery::rep()" << '\n';
        return "(" + lhs_.rep() + " " + op_sym_ + " " + rhs_.rep() + ")";
    }

    Query lhs_, rhs_;
    std::string op_sym_;
};

#endif  // BINARY_QUERY_H_
