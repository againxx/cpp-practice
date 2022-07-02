#include <iostream>
#include <vector>

struct State {
    int num;
    int previous_height = 0;
    bool begin_to_decrease = false;
};

int main() {
    int p_num, height;
    std::vector<int> heights;
    while (std::cin >> p_num) {
        for (int i = 0; i < p_num; ++i) {
            std::cin >> height;
            heights.push_back(height);
        }
        std::vector<State> previous_choir(p_num);
        std::vector<State> current_choir(p_num);
        for (int i = 0; i < p_num; ++i) {
            current_choir[i]
        }
    }
    return 0;
}
