/* Zdefiniuj początkowe liczby harmoniczne posługując się statyczną
 * arytmetyką liczb wymiernych z wykorzystaniem szablonu ratio. 
 * Jaką największą liczbę harmoniczną udało Ci się zdefiniować?
 */

#include <ratio>
#include <cstdint>
#include <iostream>
#include <type_traits>

using namespace std;

//template <intmax_t N>
//struct harmonic {
//    using value_type = ratio_add<harmonic<N-1>, ratio<1, N>>;
//};
//
//template <>
//struct harmonic<0> {
//    using value_type = ratio<0>;
//};
//
//template<bool B>
//struct sif {};
//
//template<>
//struct sif<true> { static constexpr bool v = true; };
//
//template<>
//struct sif<false> { static constexpr bool v = false; };


template <intmax_t N>
struct harmonic : public ratio_add<harmonic<N-1>, ratio<1,N>> {};

template <>
struct harmonic<0> : public ratio<0> {};


int main(){
    using max_harmonic = harmonic<46>;
    //using max_harmonic = harmonic<47>;

    cout << max_harmonic::num << "\n";
    
//    cout << sif<ratio_equal<ratio<0>, ratio<0>>::value>::v << "\n";
//    cout << sif<ratio_equal<ratio<1>, ratio<0>>::value>::v << "\n";
//
//    cout << sif<ratio_equal<harmonic<0>::value_type, ratio<0>>::value>::v << "\n";
//
//    // ----------------
//
//    cout << ratio_equal<ratio<1>, ratio<0>>::value << "\n";
//    cout << ratio_equal<harmonic<0>::value_type, ratio<0>>::value << "\n";
//
//    
//    cout << ratio_equal<harmonic<1>::value_type, ratio<1>>::value << "\n";

    return 0;
}
