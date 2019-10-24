/* Wypisz najmniejszą i największą wartość jaką można zapisać w
 * typie long long int. Na ilu bitach jest ta liczba zapisywana i
 * ile to będzie cyfr dziesiętnych?
 */

/* digits - number of radix digits that can be represented without
 * change.
 * long long: CHAR_BIT*sizeof(long long)-1
 *
 * digits10 - number of decimal digits that can be represented
 * without change. 
 * long long: std::numeric_limits<long long>::digits * std::log10(2)
 *
 * max_digits10 - number of decimal digits necessary to
 * differentiate all values of this type. Meaningful for
 * floating-point values.
 *
 * radix - the radix or integer base used by the representation of
 * the given type
 */

#include <limits>
#include <iostream>

using namespace std;

int main(){
    cout << "min=" << numeric_limits<long long int>::min() << " "
         << "max=" << numeric_limits<long long int>::max() << " "
         << "bits=" << sizeof(long long int) * 8 << " "
         << "digits10=" << numeric_limits<long long int>::digits10 
         << "\n";

    return 0;
}
