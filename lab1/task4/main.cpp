#include <cstdint>
#include <iostream>
enum class Names: uint16_t 
{
    adam,
    anna,
    maciej, // c++11 extra comma
};

void pozdro600(const std::string &c, Names n){
    std::cout << c << " ";

    switch(n){
        case Names::adam:
            std::cout << "Adam";
            break;

        case Names::anna:
            std::cout << "Anna";
            break;

        case Names::maciej:
            std::cout << "Maciej";
            break;
    }
    std::cout << "\n";

}

int main(){
    
    pozdro600("Witaj", Names::adam);

    return 0;
}
