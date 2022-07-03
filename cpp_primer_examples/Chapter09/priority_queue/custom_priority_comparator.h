#ifndef CUSTOM_PRIORITY_COMPARATOR_H_
#define CUSTOM_PRIORITY_COMPARATOR_H_

#include <vector>
#include <string>
#include <utility>
#include <queue>

class CustomPriorityComparator {
public:
    std::vector<std::string> sortString(const std::vector<std::string>&);

private:
    using DataType = std::pair<std::string::size_type, std::string>;

    bool customComparator(const DataType&, const DataType&);

    std::priority_queue<
        DataType,
        std::vector<DataType>,
        bool (*)(const DataType&, const DataType&)
        > priority_queue_{
            [](auto lhs, auto rhs) {
                return lhs.first > rhs.first;
            }};
};

#endif  // CUSTOM_PRIORITY_COMPARATOR_H_
