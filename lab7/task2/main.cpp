#include <iostream>
#include <complex>
#include <vector>
#include <random>
#include <utility>
#include <fstream>

auto dzeta(const std::complex<double> &z, size_t iter) {
    using std::complex;
    complex<double> s{0};

    for(size_t n = 1; n <= iter; n++)
        s += pow(1.0/(double)n, z);
    return s;
}

auto values(size_t iter){
    std::vector<std::pair<double, double>> v;
    std::uniform_real_distribution<double> unif(0, 8);
    std::default_random_engine re;

    double im = 0.0;
    for(size_t i=0; i<iter; i++){
        auto result = dzeta({0.5, im}, 1000);
        v.emplace_back(result.real(), result.imag());
        im += unif(re);
    }

    return v;
}

void csv_store(
    const std::vector<std::pair<double, double>> &v,
    const std::string &filename     
){
    std::ofstream ostrm{filename, std::ios::out | std::ios::app};
    ostrm << "real, imag\n";

    for(const auto &p : v)
        ostrm << p.first << ", " << p.second << "\n";
}

int main(){
    auto vect = values(1000);
    csv_store(vect, "dzeta.csv");



    return 0;
}
