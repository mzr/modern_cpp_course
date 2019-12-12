#include <stdint.h>
#include <limits.h>
#define _GLIBCXX_REGEX_STATE_LIMIT INT_MAX

#include <regex>
#include <iostream>
#include <string>

int main(){
    std::string s(
#include "regex"
            );
    std::regex re(
            s
    );

    for (std::string line; std::getline(std::cin, line);) 
        std::cout << line << ", " 
                  << std::regex_match(line, re) << "\n";

    return 0;
}
