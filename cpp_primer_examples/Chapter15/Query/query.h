#ifndef QUERY_H_
#define QUERY_H_

#include <string>
#include "query_base.h"
#include "text_query.h"

class Query {
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
public:
    explicit Query(const std::string&);
    QueryResult eval(const TextQuery& t) const {
        std::cout << "Query eval()" << '\n';
        return q->eval(t);
    }
    std::string rep() const {
        std::cout << "Query::rep()" << '\n';
        return q->rep();
    }

private:
    Query(std::shared_ptr<QueryBase> query) : q(query) { }
    std::shared_ptr<QueryBase> q;
};

std::ostream& operator<<(std::ostream& os, const Query& query);

#endif  // QUERY_H_
