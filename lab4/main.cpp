/* Stwórz w swoim programie trzy zbiory danych różnego typu 
 * vector<double>, list<string> i set<int>. Wypełnij te kontenery 
 * przypadkowymi wartościami (możesz losować albo arbitralnie coś 
 * wpisać). Następnie na zbiorach tych wykonaj pewne obliczenia z 
 * użyciem zdefiniowanych przez ciebie funktorów (obiekty funkcyjne 
 * albo lambdy):
 *
 * Zadanie 1 (1 pkt).
 * Wypisz wszystkie wartości z zadanego zakresu (większe od a i 
 * mniejsze od b).
 * Zadanie 2 (1 pkt).
 * Wypisz co k-tą wartość zaczynając od pozycji p-tej.
 * Zadanie 3 (1 pkt).
 * Wyznacz średnią arytmetyczną (dotyczy kolekcji z liczbami).
 * Zadanie 4 (1 pkt).
 * Wyznacz element minimalny i maksymalny (zwróć parę iteratorów).
 * Zadanie 5 (1 pkt).
 * Wyznacz sumę/konkatenację wszystkich elementów.
 */

#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main(){

    vector<double> v{1.3, 5.1, 3,3.2,2,7,89,5,32,3,5,8,9,4,2};
    set<int> s{1,5,3,3,2,7,89,5,32,3,5,8,9,4,2};
    list<string> l{"sdf", "xcvb", "asd", "evcasdf", "ifdvsafrg"};

    // Task1:
    cout << "Task1:\n";
    for_each(v.begin(), v.end(), 
        [](const auto& n){
            if(n > 3 && n < 9)
                cout << n << " ";
        }
    );

    cout << "\n";

    for_each(s.begin(), s.end(), 
        [](const auto& n){
            if(n > 3 && n < 9)
                cout << n << " ";
        }
    );

    cout << "\n";

    for_each(l.begin(), l.end(), 
        [](const auto& n){
            if(n > "asd" && n < "xc")
                cout << n << " ";
        }
    );
    cout << "\n";


    // Task2:
    cout << "Task2:\n";
    //TODO
    // Wypisz co k-tą wartość zaczynając od pozycji p-tej.
    
    cout << "\n";


    // Task3:
    cout << "Task3:\n";
    cout << accumulate(v.begin(), v.end(), 0) / v.size() << "\n";
    cout << accumulate(s.begin(), s.end(), 0) / s.size() << "\n";
    cout << "\n";

    // Task4:
    cout << "Task4:\n";
    cout << *max_element(v.begin(), v.end()) << " "
         << *min_element(v.begin(), v.end()) << "\n";
    cout << *max_element(s.begin(), s.end()) << " "
         << *min_element(s.begin(), s.end()) << "\n";
    cout << *max_element(l.begin(), l.end()) << " "
         << *min_element(l.begin(), l.end()) << "\n";
    cout << "\n";

    // Task5:
    cout << "Task5:\n";
    cout << accumulate(v.begin(), v.end(), 0) << "\n";
    cout << accumulate(s.begin(), s.end(), 0) << "\n";
    cout << accumulate(l.begin(), l.end(), string{}) << "\n";
    cout << "\n";

    return 0;
}
