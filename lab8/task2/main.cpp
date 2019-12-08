#include <regex>
#include <iostream>

int main(){
    std::regex re("((((([0-2][0-9])|(3[01]))-((0[13578])|(1[02])))|((([0-2][0-9])|(30))-((0[469])|(11))))-([0-9]{4,}))|(((1[0-9])|(2[0-8]))-02-[0-9]{4,})");

    for (std::string line; std::getline(std::cin, line);) 
        std::cout << line << ", " 
                  << std::regex_match(line, re) << "\n";

    return 0;
}
