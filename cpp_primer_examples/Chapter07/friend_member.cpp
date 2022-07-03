#include <cstddef>
#include <string>
#include <vector>

class Screen;

class WindowManager {
public:
    using ScreenIdx = std::vector<Screen>::size_type;

    void clear(ScreenIdx i);

private:
    std::vector<Screen> screens;
};

class Screen {
public:
    friend void WindowManager::clear(ScreenIdx);

    using pos = std::string::size_type;

    Screen() = default;

    Screen(size_t h, size_t w, char c) :
        height(h), width(w), contents(h * w, c) { }

    char get() const {
        return contents[cursor];
    }

    char get(pos r, pos c) const {
        return contents[r * width + c];
    }

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
};

void WindowManager::clear(ScreenIdx i) {
    Screen& s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

int main() {
    WindowManager win_mgr;
    return 0;
}
