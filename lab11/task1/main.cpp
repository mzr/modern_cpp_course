/* Wykorzystując metaprogramowanie zdefiniuj szablon obiektu 
 * funkcyjnego, pozwalającego obliczyć na poziomie kompilacji 
 * n-tą liczbę Lucasa dla liczby naturalnej n ≥ 0. Funkcja 
 * powinna działać w liniowym czasie O(n).
 */


/* L(n) = 2                 if n == 0
 *        1                 if n == 1
 *        L(n-1) + L(n-2)   if n > 1
 */

#include <iostream>
#include <cstdint>

template <intmax_t N>
struct lucas_num{
    static constexpr uint64_t val = lucas_num<N-1>::val + lucas_num<N-2>::val;
};

template <>
struct lucas_num<0> {
    static constexpr uint64_t val = 2;
};

template <>
struct lucas_num<1> {
    static constexpr uint64_t val = 1;
};

int main(){
    std::cout << lucas_num<0>::val << "\n";
    std::cout << lucas_num<1>::val << "\n";
    std::cout << lucas_num<2>::val << "\n";
    std::cout << lucas_num<3>::val << "\n";
    std::cout << lucas_num<4>::val << "\n";
    std::cout << lucas_num<5>::val << "\n";
    std::cout << lucas_num<6>::val << "\n";
    std::cout << lucas_num<7>::val << "\n";
    std::cout << lucas_num<8>::val << "\n";
    std::cout << lucas_num<60>::val << "\n";

    return 0;
}
