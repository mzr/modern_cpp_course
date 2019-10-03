#include <iostream>
#include <cmath>


static inline auto delta(int a, int b, int c){
    return b*b - 4*a*c;
}



int main(int argc, char **argv){

    auto a{-2};
    auto b{3};
    auto c{-1};
    
    if(auto d{delta(a,b,c)}; d >= 0){
        if(d == 0)
            std::cout << -b / (2*a) << "\n";
        else
            std::cout << ((-b) - std::sqrt(d)) / (2*a) 
                      << " "
                      << ((-b) + std::sqrt(d)) / (2*a) 
                      << "\n";

    } 
    else
        std::cout << "No roots.\n";

    return 0;
}
