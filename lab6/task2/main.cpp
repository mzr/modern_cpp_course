/* Napisz program, który wygeneruje 1000 losowych liczb z rozkładem:
 * - jednostajnym, używając uniform_real_distribution;
 * - dwumianowym, używając binomial_distribution;
 * - normalnym, używając normal_distribution.
 *
 * Wygenerowane liczby zapisz w pliku .csv (dla każdego rozkładu w 
 * osobnym pliku). Zrób w arkuszu kalkulacyjnym wykresy dla danych 
 * wygenerowanych w taki sposób, aby sprawdzić poprawność 
 * zastosowanego rozkładu prawdopodobieństwa.
 */

#include <random>
#include <iostream>
#include <array>
#include <fstream>
#include <string>

// TODO better generic param passing
// variadic?
template <typename Dist, typename ValType, typename P1, typename P2>
auto rand_arr(P1 param1, P2 param2){
    std::array<ValType, 1000> a;
    std::random_device rd;
    std::mt19937 gen{rd()};
    
    Dist dis{param1, param2};
    for(int i=0; i<1000; i++)
        a[i] = dis(gen);

    return a;
}

template <size_t N, typename T>
void csv_store(
    const std::array<T, N> &a, 
    const std::string &filename
){
    std::ofstream ostrm(filename, std::ios::out | std::ios::app);
    for(const auto &e : a){
        ostrm << e << ",";
    }
}

int main(){
    auto normal_ar = 
        rand_arr<std::normal_distribution<>, double>(0.0, 1.0);
    auto uniform_ar = 
        rand_arr<std::uniform_real_distribution<>, double>(0.0, 1.0);
    auto binom_arr = 
        rand_arr<std::binomial_distribution<>, int>(4, 0.5);

    csv_store(normal_ar, "normal.csv");    
    csv_store(normal_ar, "uiform.csv");    
    csv_store(normal_ar, "binom.csv");    


    return 0;
}
