#ifndef QUERY_RESULT_H_
#define QUERY_RESULT_H_

#include <set>
#include <memory>
#include <vector>
#include <string>

class QueryResult {
friend void print(std::ostream& os, const QueryResult& query_result);
public:
    QueryResult(const std::string& word,
                int occur_times,
                const std::shared_ptr<std::set<std::size_t>>& line_nums,
                const std::shared_ptr<std::vector<std::string>>& input_line) :
                word_(word),
                occur_times_(occur_times),
                line_nums_(line_nums),
                input_lines_(input_line) { }

private:
    std::string word_;
    unsigned occur_times_ = 0;
    std::shared_ptr<std::set<std::size_t>> line_nums_;
    std::shared_ptr<std::vector<std::string>> input_lines_;
};

void print(std::ostream& os, const QueryResult& query_result);

#endif  // QUERY_RESULT_H_
