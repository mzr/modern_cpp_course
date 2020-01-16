/* Wykorzystując metaprogramowanie zdefiniuj szablon obiektu 
 * funkcyjnego, pozwalającego obliczyć na poziomie kompilacji 
 * największy wspólny dzielnik NWD(a, b) dla liczb naturalnych 
 * a, b ≥ 1 dla naturalnych liczb 0 ≤ k ≤ n. Funkcja powinna 
 * działać w logarytmicznym czasie O(log a + log b).
 */

#include <cstdint>
#include <iostream>

template <size_t N, size_t K>
struct gcd{
    static constexpr uint64_t val = gcd<K, N % K>::val;
};

template <size_t N>
struct gcd<N,0> {
    static constexpr uint64_t val = N;
};


int main(){

    std::cout << gcd<185, 105>::val;

    return 0;
}
