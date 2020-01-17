#include <iostream>

template <size_t n, size_t k>
struct binom;

template <size_t n, size_t k>
struct binom{
    constexpr static size_t val = (binom<n-1, k-1>::val * n) / k;
};

template<>
struct binom<0,0>{
    constexpr static size_t val = 1;
};

template<size_t n>
struct binom<n,0>{
    constexpr static size_t val = 1;
};

template<size_t n>
struct binom<n,n>{
    constexpr static size_t val = 1;
};

int main(){

    std::cout << binom<5, 2>::val << "\n";
    std::cout << binom<100, 50>::val << "\n";
    std::cout << binom<8, 6>::val << "\n";

    return 0;
}
