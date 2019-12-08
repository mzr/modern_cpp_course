#include <regex>
#include <iostream>

int main(){

    std::regex re("((0[0-9])|(1[0-9])|(2[0-3])):([0-5][0-9])(:([0-5][0-9]))?");
 
    for (std::string line; std::getline(std::cin, line);)                       
        std::cout << line << ", "                                               
                  << std::regex_match(line, re) << "\n";


    return 0;
}
