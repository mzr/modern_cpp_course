#include <regex>
#include <iostream>

int main(){
    std::regex re(R"EOF(\(\s*([1-9]\d*|0)(\.\d+)?\s*\+\s*([1-9]\d*|0)(\.\d+)?i\s*\))EOF");

    for (std::string line; std::getline(std::cin, line);) 
        std::cout << line << ", " 
                  << std::regex_match(line, re) << "\n";

    return 0;
}
