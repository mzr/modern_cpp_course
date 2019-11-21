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

#include <utility>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iterator>

using namespace std;


int main(){

    vector<double> v{1.3, 5.1, 3,3.2,2,7,89,5,32,3,5,8,9,4,2};
    set<int> s{1,5,3,3,2,7,89,5,32,3,5,8,9,4,2};
    list<string> l{"sdf", "xcvb", "asd", "evcasdf", "ifdvsafrg"};
    

    cout << "Task1:\n";
    auto task1 = [](const auto &c, auto a, auto b){
        for(const auto &e : c)
            if( e > a && e < b)
                cout << e << " ";
        cout << "\n";
    };

    task1(v, 3,9);
    task1(s, 3,9);
    task1(l, "asd", "xc");



    // Task2:
    cout << "Task2:\n";
    auto task2 = [](const auto &c, int k, int p){
        auto it = c.begin();
        advance(it, p);
        for(int i=0; it != c.end(); ++it, ++i)
            if(i%k == 0)
                cout << *it << " ";
        cout << "\n";
    };

    task2(v, 2, 1);
    task2(s, 2, 1);
    task2(l, 2, 1);


    // Task3:
    cout << "Task3:\n";
    auto task3 = [](const auto &c){
        return accumulate(c.begin(), c.end(), 0) / c.size();
    };
    cout << task3(v) << "\n";
    cout << task3(s) << "\n";

    // Task4:
    cout << "Task4:\n";
    auto task4 = [](const auto &c){
        auto it_min = c.begin();
        auto it_max = c.begin();
        for(auto it=c.begin(); it!=c.end(); ++it){
            if(*it < *it_min) it_min = it;
            if(*it > *it_max) it_max = it;
        }
        return make_pair(it_min, it_max);
    };
    auto v_min_max = task4(v);
    cout << "v: min=" << *v_min_max.first << " max=" << *v_min_max.second << "\n";

    auto s_min_max = task4(s);
    cout << "s: min=" << *s_min_max.first << " max=" << *s_min_max.second << "\n";

    auto l_min_max = task4(l);
    cout << "l: min=" << *l_min_max.first << " max=" << *l_min_max.second << "\n";

    // Task5:
    cout << "Task5:\n";
    auto task5 = []<typename C>(const C &c){
        using T = typename C::value_type;
        return accumulate(c.begin(), c.end(), T{});
    };
    
    cout << "v: " << task5(v) << "\n";
    cout << "s: " << task5(s) << "\n";
    cout << "l: " << task5(l) << "\n";


    return 0;
}
