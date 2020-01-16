/* Wykorzystując metaprogramowanie zdefiniuj szablon obiektu 
 * funkcyjnego, pozwalającego obliczyć na poziomie kompilacji 
 * współczynnik dwumianowy (nk) dla liczb naturalnych 0 ≤ k ≤ n. 
 * Funkcja powinna działać w liniowym czasie O(n).
 */

#include <iostream>

template<size_t n, size_t k>
struct Binomial;

template<size_t n, size_t k, bool outOfBounds>
struct BinomialCompute;

template<size_t n, size_t k>
struct BinomialCompute<n, k, true> {

  static const size_t value = 0;
};

template<size_t n, size_t k>
struct BinomialCompute<n, k, false> {

  static const size_t value = (Binomial<n-1,k-1>::value + Binomial<n-1,k>::value);
};

template<size_t n, size_t k>
struct Binomial {
  static const size_t value =  BinomialCompute<n, k, n < k>::value;
};

template<>
struct Binomial<0,0> {
  static const size_t value = 1;
};

template<size_t n>
struct Binomial<n,0> {
  static const size_t value = 1;
};

template<size_t n>
struct Binomial<n,n> {
  static const size_t value = 1;
};


int main(){
    std::cout << Binomial<5,2>::value << "\n";
    std::cout << Binomial<6,4>::value << "\n";

    return 0;
}
