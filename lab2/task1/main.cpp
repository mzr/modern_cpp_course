/* Zadanie 1 (5 pkt).
 * Zdefiniuj prostą klasę zawierającą licznik typu uint64_t, 
 * początkowo ustawiony na wartość 1. Następnie stwórz 
 * n-elementową tablicę takich liczników i opakuj ją wskaźnikiem 
 * unique_ptr. Napisz też funkcję, która wywoła się rekurencyjnie 
 * m razy z taką tablicą - w i-tym wywołaniu funkcja ta ma losowo 
 * wybrane elementy przemnożyć przez i-ta z kolei liczbę pierwszą.
 * Na koniec wywołaj tą funkcję, a po jej wywołaniu wypisz wartości 
 * wszystkich n liczników w tablicy. Parametry n i m możesz ustalić 
 * arbitralnie.
 */

#include <iostream>
#include <memory>
#include <cstdint>
#include <vector>
#include <random>

struct Counter{

    uint64_t value = 1;

    Counter() {
        std::cout << std::hex << this << std::dec << ":\tdefault constructor\n";
    }

    ~Counter(){
        std::cout << std::hex << this << std::dec << ":\tdestructor\n";
    }

};

bool is_prime(unsigned int n){
    if(n == 1)
        return false;

    for(int i=2; i*i <= n; i++)
        if(n%i == 0)
            return false;

    return true;
}

int nth_prime(int n){
    int seen_primes = 0;
    int state = 2;
    while(seen_primes < n){
        do{
            state++;
        } while(!is_prime(state));
        seen_primes++;
    }

    return state;
}


void mul_arr(std::unique_ptr<Counter[]> arr, int size, int m, int nth){
    if(m == 0)
        return;
    
    int index = rand() % size;
    arr[index].value *= nth_prime(nth);
    mul_arr(arr, size, m-1, nth+1); 
}


int main(){

    size_t n = 10;
    int m = 10;
    
    auto arr = std::make_unique<Counter[]>(n);

    mul_arr(arr, n, m, 0);
    
    for(int i=0; i<n; i++){
        std::cout << arr[i].value << " ";
    }
    std::cout << "\n";
    

    return 0;
}
