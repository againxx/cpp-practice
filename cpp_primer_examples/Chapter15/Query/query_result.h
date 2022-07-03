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

    std::set<std::size_t>::const_iterator begin() const { return line_nums_->cbegin(); };
    std::set<std::size_t>::const_iterator end() const { return line_nums_->cend(); };
    std::shared_ptr<std::vector<std::string>> get_file() const { return input_lines_; }
    unsigned get_occur_times() const { return occur_times_; }

    using line_no = std::vector<std::string>::size_type;

private:
    std::string word_;
    unsigned occur_times_ = 0;
    std::shared_ptr<std::set<line_no>> line_nums_;
    std::shared_ptr<std::vector<std::string>> input_lines_;
};

void print(std::ostream& os, const QueryResult& query_result);

#endif  // QUERY_RESULT_H_
