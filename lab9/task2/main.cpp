/* Niech Φ(n) oznacza funkcję Eulera (tocjent), która dla każdej 
 * dodatniej liczby naturalnej zwraca liczbę liczb naturalnych nie 
 * większych od n i względnie pierwszych z n. Dla zadanej wartości 
 * k stablicuj kolejne wartości tocjenta Φ(1),Φ(2),…,Φ(k) a 
 * następnie zapisz je do pliku phi.txt, używając iteratora 
 * strumieninowego ostream_iterator z separatorem w postaci 
 * średnika i spacji "; ".
 */

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <type_traits>
#include <numeric>

int totient(int n){
    int result{0};
    for(int i=n; i>0; i--)
        if(std::gcd(i, n) == 1)
            result++;
    return result;
}
    

int main(int argc, char **argv){
    if(argc < 2){
        std::cout << "Usage: " << argv[0] << ": [k]" << std::endl;
        return 1;
    }
    int k = atoi(argv[1]);
    
    std::vector<int> results;

    for(int i=1; i<k; i++)
        results.emplace_back(totient(i));

    std::ofstream of{"phi.txt", std::ios::out};
    std::ostream_iterator<int> out_it(of, "; ");
    std::copy(results.begin(), results.end(), out_it);

    return 0;
}
