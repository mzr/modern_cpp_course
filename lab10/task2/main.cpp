/* Dane o kolorowych punktach na płaszczyźnie są zgromadzone w 
 * liście. Pojedynczy punkt jest opisany za pomocą współrzędnych, 
 * koloru w postaci RGB i nazwy. Podziel te punkty na takie, które 
 * leżą w I, II, III i IV ćwiartce. Wypisz także jaki punkt jest 
 * najjaśniejszy a jaki najciemniejszy.
 */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

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
    std::vector<std::vector<Point>> quadrants(4);

    for(int i=0; i<4; i++)
        std::copy_if(
            points.begin(),
            points.end(),
            quadrants[i].begin(),
            [&i](const Point &p){
                switch(i){
                case 0: return  p.x > 0 && p.y > 0;
                case 1: return  p.x < 0 && p.y > 0;
                case 2: return  p.x < 0 && p.y < 0;
                case 3: return  p.x > 0 && p.y < 0;
                default: return false;
                }
            }
        );



    return 0;
}
