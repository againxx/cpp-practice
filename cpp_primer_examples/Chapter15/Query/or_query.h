#ifndef OR_QUERY_H_
#define OR_QUERY_H_

#include "binary_query.h"

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query& lhs, const Query& rhs);
    OrQuery(const Query& lhs, const Query& rhs) :
        BinaryQuery(lhs, rhs, "|") { }
    QueryResult eval(const TextQuery&) const override;
};

inline Query operator|(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

#endif  // OR_QUERY_H_
