#include <algorithm>
#include <iterator>
#include "and_query.h"

QueryResult AndQuery::eval(const TextQuery& text) const {
    auto left_result = lhs_.eval(text);
    auto right_result = rhs_.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::set_intersection(left_result.begin(), left_result.end(),
                          right_result.begin(), right_result.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines->size(), ret_lines,
                       left_result.get_file());
}
