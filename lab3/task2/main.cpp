/* Jaka jest najbliższa 0 liczba dodatnia i liczba ujemna dla 
 * typów float i double? Jakie są maksymalne wartości zapisywane 
 * w tych typach? Jaka jest różnica pomiędzy 1 a najmniejszą 
 * liczbą <=1 w tych typach?
 */

#include <iostream>
#include <limits>
#include <limits.h>
#include <cmath>

using namespace std;

template <typename T>
void values(){
    cout << typeid(T).name() << "\n"
         // min to najmniejsza znormalizowana wieksza od 0
         << "min=" << numeric_limits<T>::min() << "\n"
         // denorm_min to najmniejsza zdenormalizowana wieksza od 0
         << "denorm_min=" << numeric_limits<T>::denorm_min() << "\n"
         // lowest to najmniejsza w ogole (czyli <0)
         << "lowest=" << numeric_limits<T>::lowest() << "\n"
         // max to najwieksza w ogole (czyli >0)
         << "max=" << numeric_limits<T>::max() << "\n"
         << "sizeof=" << sizeof(T) << "\n";
}

int main(){
    values<float>();
    cout << "\n";
    values<double>();

    cout << "1f - (1f - epsf): " 
         << 1.0f - nextafterf(1.0f, 0.0f) << "\n";

    cout << "1d - (1d - epsd): " 
         << 1.0 - nextafter(1.0, 0.0) << "\n";

    return 0;
}
