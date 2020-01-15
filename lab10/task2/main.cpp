/* Dane o kolorowych punktach na płaszczyźnie są zgromadzone w 
 * liście. Pojedynczy punkt jest opisany za pomocą współrzędnych, 
 * koloru w postaci RGB i nazwy. Podziel te punkty na takie, które 
 * leżą w I, II, III i IV ćwiartce. Wypisz także jaki punkt jest 
 * najjaśniejszy a jaki najciemniejszy.
 */

/* I think what you are looking for is the RGB -> Luma conversion formula.

Photometric/digital ITU BT.709:

Y = 0.2126 R + 0.7152 G + 0.0722 B
Digital ITU BT.601 (gives more weight to the R and B components):

Y = 0.299 R + 0.587 G + 0.114 B
*/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

struct Point{
    std::string name;
    double x;
    double y;

    unsigned char r;
    unsigned char g;
    unsigned char b;

    double luminence() const {
        return 0.299 * r + 0.587 * g + 0.114 * b;
    }
};

std::list<Point> points{
    {"punkt1", 0.1, 0.4, 120, 234, 5},
    {"punkt2", 1.2, -0.4, 120, 234, 5},
    {"punkt3", 1.2, -0.4, 120, 12, 5},
    {"punkt4", 1.2, -0.4, 150, 234, 5},
};

int main(){
    std::vector<std::vector<Point>> quadrants(4);

    for(int i=0; i<4; i++)
        std::copy_if(
            points.begin(),
            points.end(),
            //quadrants[i].begin(), // predzej jakis back inserter
            std::back_inserter(quadrants[i]),
            [&i](const Point &p) -> bool{
                switch(i){
                case 0: return p.x > 0 && p.y > 0;
                case 1: return p.x < 0 && p.y > 0;
                case 2: return p.x < 0 && p.y < 0;
                case 3: return p.x > 0 && p.y < 0;
                default: return false;
                }
            }
        );

    for(int i=0; i<4; i++){
        std::cout << "quadrant " << i + 1 << ":\n";
        for(const auto &p : quadrants[i]){
            std::cout << p.x << " " << p.y << " " << p.luminence() << "\n";
        }
    }
    
    std::cout << "brightest:\n";
    auto brightest = std::max_element(
        points.begin(),
        points.end(),
        [](const Point &a, const Point &b){
            return a.luminence() < b.luminence();
        }
    );
    std::cout << brightest->name << "\n";


    std::cout << "darkest:\n";
    auto darkest = std::min_element(
        points.begin(),
        points.end(),
        [](const Point &a, const Point &b){
            return a.luminence() < b.luminence();
        }
    );
    std::cout << darkest->name << "\n";

    return 0;
}
