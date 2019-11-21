/* Zdefiniuj szablon funkcji, ktory losowo spermutuje zadana 
 * tablice obiektow. Kazda permutacja ma byc jednakowo prawdopodobna.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <experimental/random>

using namespace std;

template <typename C>
void permute_random(C &c){
    random_shuffle(c.begin(), c.end()); 
}

// Fisher–Yates shuffle
template <typename C>
void permute_random2(C &c){
    for(int i=c.size()-1; i >= 1; i--){
        int j = experimental::randint(0, i);
        swap(c[j], c[i]);
    }
}

template <typename C>
void print_container(const C &c){
    for(const auto &e : c)
        cout << e << " ";
    cout << "\n";    
}

int main(){
    array<int, 100> a = {1,2,3,4}; 
    print_container(a);
    permute_random(a); 
    cout << "\n";
    print_container(a);



    return 0;
}
