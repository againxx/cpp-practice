#include "or_query.h"

QueryResult OrQuery::eval(const TextQuery& text) const {
    auto right_result = rhs_.eval(text);
    auto left_result = lhs_.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>(left_result.begin(),
                                                         left_result.end());

    ret_lines->insert(right_result.begin(), right_result.end());
    return QueryResult(
        rep(), left_result.get_occur_times() + right_result.get_occur_times(),
        ret_lines, left_result.get_file());
}
