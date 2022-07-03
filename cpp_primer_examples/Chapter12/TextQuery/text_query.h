#ifndef TEXT_QUERY_H_
#define TEXT_QUERY_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>

#include "query_result.h"

class TextQuery {
public:
    explicit TextQuery(std::ifstream& input_file);

    QueryResult query(const std::string& word) const;

private:
    std::shared_ptr<std::vector<std::string>>
        input_lines_{new std::vector<std::string>};
    std::map<std::string, std::shared_ptr<std::set<std::size_t>>>
        word_line_nums_;
    std::map<std::string, std::size_t> word_counts_;
};

#endif  // TEXT_QUERY_H_
