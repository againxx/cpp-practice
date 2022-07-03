#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <string>

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

int main() {
    std::vector<std::string> story = {
        "the", "quick", "red", "fox", "jumps", "over",
        "the", "slow", "red", "turtle"};
    // elimDups(story);
    // std::stable_sort(story.begin(), story.end(), isShorter);
    auto ret = std::partition(story.begin(), story.end(),
            [](const std::string &s){ return s.size() >= 5; });
    // for (const auto& i : story)
    //     std::cout << i << ' ';
    for (auto it = story.cbegin(); it != ret; ++it) {
        std::cout << *it << '\n';
    }
    return 0;
}
