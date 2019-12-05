#include <iostream>
#include <complex>

auto gamma(const std::complex<double> &z, size_t iter) {
    using std::complex;
    complex<double> c{1};

    for(size_t n=1; n <= iter; n++)
        c *= pow(1.0 + 1.0/(double)n, z) / (1.0 + z/(double)n);

    return c / z;
}

auto inv_gamma(const std::complex<double> &z, size_t iter) {
    using std::complex;
    const double euler_mascheroni = 0.5772156649;
    complex<double> c{1};

    for(size_t n=1; n <= iter; n++)
        c *= ((1.0 + z/(double)n) * exp(-z/(double)n));

    return z*exp(euler_mascheroni*z)*c;
}


int main(){
    auto val1 = gamma(std::complex<double>{5.0}, 10000);
    auto val2 = inv_gamma(std::complex<double>{5.0}, 10000);

    std::cout << val1 << "\n";
    std::cout << val2 << "\n";

    return 0;
}
