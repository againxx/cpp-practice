#include <ostream>
#include "query_result.h"

void print(std::ostream& os, const QueryResult& query_result) {
    os << query_result.word_ << " occurs "
       << query_result.occur_times_ << " times\n";

    if (query_result.line_nums_) {
        for (auto i : *query_result.line_nums_) {
        os << "(line " << i + 1 << ") ";
        os << (*query_result.input_lines_)[i] << '\n';
        }
    }
}
