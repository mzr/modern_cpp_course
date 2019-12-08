#include <regex>
#include <iostream>

int main(){

    const std::string hours[] = {
        "00:00", 
        "09:03", 
        "24:00", 
        "9:3",
        "01:23:50",
        "01:23:",
        "01:23:60",
        "01:23:6",
        "01:23:06",
    };
    std::regex re("((0[0-9])|(1[0-9])|(2[0-3])):([0-5][0-9])(:([0-5][0-9]))?");
 
    for (const auto &h: hours) 
        std::cout << h << ", " << std::regex_match(h, re) << '\n';


    return 0;
}
