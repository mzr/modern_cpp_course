/* Odczytaj ze standardowego wejścia jedną linię z danymi - ciąg 
 * liczb rzeczywistych pooddzielanych spacjami. Używając iteratora 
 * strumieniowego istream_iterator odczytaj te liczby, zapisz je w 
 * wektorze i wypisz na standardowym wyjściu w odwrotnej kolejności 
 * z dokładnością do 3 miejsc po kropce dziesiętnej.
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    
    auto vec = vector<double>(
            istream_iterator<double>(cin), 
            istream_iterator<double>()
        );
    
    for_each(vec.rbegin(), vec.rend(), [](const double &e){
        cout.precision(4);
        cout << e << " ";
    });


    return 0;
}
