#ifndef WORDQUERY_H_
#define WORDQUERY_H_

#include "query_base.h"

class WordQuery : public QueryBase {
    friend class Query;

private:
    explicit WordQuery(const std::string& s) : query_word_(s) { }
    QueryResult eval(const TextQuery& t) const override {
        std::cout << "WordQuery eval()" << '\n';
        return t.query(query_word_);
    }
    std::string rep() const override {
        std::cout << "WordQuery::rep()" << '\n';
        return query_word_;
    }
    std::string query_word_;
};

#endif  // WORDQUERY_H_
