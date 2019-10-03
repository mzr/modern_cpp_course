// g++ main.cpp -std=c++2a -fconcepts -o main && ./main
#include <iostream>

auto lucas(auto n){
    if (n == 0)
        return 2;
    if (n == 1)
        return 1;
    return lucas(n-1) + lucas(n-2);
}

int main(){

    std::cout << lucas(10) << "\n";

    return 0;
}
