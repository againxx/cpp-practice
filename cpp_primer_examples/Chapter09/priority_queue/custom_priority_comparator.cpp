#include <algorithm>
#include <iterator>
#include "custom_priority_comparator.h"

std::vector<std::string> CustomPriorityComparator::sortString(
        const std::vector<std::string>& input) {
    for (const auto& s : input) {
        priority_queue_.emplace(s.length(), s);
    }

    std::vector<std::string> result;
    result.reserve(input.size());
    while (!priority_queue_.empty()) {
        result.emplace_back(priority_queue_.top().second);
        priority_queue_.pop();
    }
    return result;
}

bool CustomPriorityComparator::customComparator(const DataType& lhs,
                                                const DataType& rhs) {
    return lhs.first > rhs.first;
}
