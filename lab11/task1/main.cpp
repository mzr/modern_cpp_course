/* Wykorzystując metaprogramowanie zdefiniuj szablon obiektu 
 * funkcyjnego, pozwalającego obliczyć na poziomie kompilacji 
 * n-tą liczbę Lucasa dla liczby naturalnej n ≥ 0. Funkcja 
 * powinna działać w liniowym czasie O(n).
 */


/* L(n) = 2                 if n == 0
 *        1                 if n == 1
 *        L(n-1) + L(n-2)   if n > 1
 */

#include <iostream>

constexpr int lucas(int n){
    if(n == 0)
        return 2;
    if(n == 1)
        return 1;
    
    int val0 = 2;
    int val1 = 1;
    int val = 0;
    
    while(n >= 2){
        val = val1 + val0;
        val0 = val1;
        val1 = val;
        
        n--;
    }

    return val;
}

int main(){
    for(int i=0; i<10; i++)
        std::cout << lucas(i) << " ";

    return 0;
}


