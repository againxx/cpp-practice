#include "text_query.h"

void runQueries(std::ifstream& infile) {
    TextQuery tq(infile);
    // while (true) {
    //     std::cout << "Enter word to look for, or q to quit: ";
    //     std::string s;
    //     if (!(std::cin >> s) || s == "q") break;
    //     print(std::cout, tq.query(s));
    // }
    std::string s;
    do {
        if (!s.empty())
            print(std::cout, tq.query(s));
        std::cout << "Enter word to look for, or q to quit: ";
    } while (std::cin >> s && s != "q");
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::ifstream input_file(argv[1]);
        runQueries(input_file);
    } else {
        std::cout << "Please input file name." << '\n';
    }
    return 0;
}
