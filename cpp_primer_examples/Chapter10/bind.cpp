#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

std::ostream& print(std::ostream &os, const std::string &s, char c) {
    return os << s << c;
}

int main() {
    std::vector<std::string> story = {
        "the", "quick", "red", "fox", "jumps", "over",
        "the", "slow", "red", "turtle"};

    using namespace std::placeholders;
    std::for_each(story.cbegin(), story.cend(),
            std::bind(print, std::ref(std::cout), _1, ' '));

    return 0;
}
