/* Dane o kolorowych punktach na płaszczyźnie są zgromadzone w 
 * liście. Pojedynczy punkt jest opisany za pomocą współrzędnych, 
 * koloru w postaci RGB i nazwy. Podziel te punkty na takie, które 
 * leżą w I, II, III i IV ćwiartce. Wypisz także jaki punkt jest 
 * najjaśniejszy a jaki najciemniejszy.
 */

#include <iostream>
#include <list>

struct Point{
    std::string name;
    double x;
    double y;

    unsigned char r;
    unsigned char g;
    unsigned char b;
};

std::list<Point> points{
    {"punkt1", 1.2, -0.4, 120, 234, 5},
    {"punkt1", 1.2, -0.4, 120, 234, 5},
    {"punkt1", 1.2, -0.4, 120, 234, 5},
    {"punkt1", 1.2, -0.4, 120, 234, 5},
};

int main(){




    return 0;
}
