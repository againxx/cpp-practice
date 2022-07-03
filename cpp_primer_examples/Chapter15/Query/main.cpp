#include <iostream>
#include <fstream>
#include "query.h"
#include "not_query.h"
#include "and_query.h"
#include "or_query.h"

int main() {
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q << '\n';
    std::ifstream ifs("../../Chapter12/TextQuery/test.txt");
    TextQuery tq(ifs);
    q.eval(tq);
    return 0;
}
