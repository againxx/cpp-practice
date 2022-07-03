#ifndef AND_QUERY_H_
#define AND_QUERY_H_

#include "binary_query.h"

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query& lhs, const Query& rhs);
    AndQuery(const Query& lhs, const Query& rhs) :
        BinaryQuery(lhs, rhs, "&") { }
    QueryResult eval(const TextQuery&) const override;
};

inline Query operator&(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

#endif  // AND_QUERY_H_
