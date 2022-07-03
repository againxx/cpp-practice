#ifndef QUERY_BASE_H_
#define QUERY_BASE_H_

#include <iostream>
#include "text_query.h"
#include "query_result.h"

class QueryBase {
    friend class Query;
protected:
    using line_no = QueryResult::line_no;
    virtual ~QueryBase() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

#endif  // QUERY_BASE_H_
