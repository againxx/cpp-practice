#ifndef NOT_QUERY_H_
#define NOT_QUERY_H_

#include "query.h"

class NotQuery : public QueryBase {
    friend Query operator~(const Query&);

private:
    NotQuery(const Query& q) : query_(q) { }
    std::string rep() const override {
        return "~(" + query_.rep() + ")";
    }
    QueryResult eval(const TextQuery&) const override;
    Query query_;
};

inline Query operator~(const Query& operand) {
    return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

#endif  // NOT_QUERY_H_
