#include <utility>
#include <sstream>
#include "text_query.h"

TextQuery::TextQuery(std::ifstream& input_file) {
    std::string line, word;
    for (std::size_t i = 0; std::getline(input_file, line); ++i) {
        std::istringstream line_stream(line);
        while (line_stream >> word) {
            if (word_line_nums_.find(word) == word_line_nums_.end())
                word_line_nums_[word] = std::make_shared<std::set<std::size_t>>();
            word_line_nums_[word]->insert(i);
            ++word_counts_[word];
        }
        input_lines_->emplace_back(std::move(line));
    }
}

QueryResult TextQuery::query(const std::string &word) const {
    static std::shared_ptr<std::set<std::size_t>>
        no_data(new std::set<std::size_t>);
    auto loc = word_line_nums_.find(word);
    if (loc == word_line_nums_.cend())
        return QueryResult(word, 0, no_data, input_lines_);
    return QueryResult(word,
                       word_counts_.find(word)->second,
                       loc->second,
                       input_lines_);
}
