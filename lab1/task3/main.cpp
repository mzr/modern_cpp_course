#include <iostream>
#include <set>

using stringset = std::set<std::string>;


int main(){

    stringset ss{"a", "be", "ce", "de"};
    for (const auto &s : ss)
        std::cout << s << "\n";

    return 0;
}
