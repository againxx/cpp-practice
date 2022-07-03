#include "gtest/gtest.h"
#include "custom_priority_comparator.h"

TEST(TestCustomPriorityComparator, sortString) {
    std::vector<std::string> unsorted_strings = {
        "hello",
        "here",
        "world!",
        "abc",
        "important"
    };

    CustomPriorityComparator custom_priority_comparator;
    auto sorted_strings =
        custom_priority_comparator.sortString(unsorted_strings);

    EXPECT_EQ(sorted_strings[0], "abc");
    EXPECT_EQ(sorted_strings[1], "here");
    EXPECT_EQ(sorted_strings[2], "hello");
    EXPECT_EQ(sorted_strings[3], "world!");
    EXPECT_EQ(sorted_strings[4], "important");
}
