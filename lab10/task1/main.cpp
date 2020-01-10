/* Dane o pewnych osobach są zgromadzone w wektorze. Pojedyncza 
 * osoba jest opisana za pomocą nazwy (imię i nazwisko), wieku, 
 * wagi i wzrostu. Posortuj te dane według współczynnika BMI i 
 * wypisz je na standardowym wyjściu (funkja porównująca niech 
 * będzie lambdą). Wypisz także jaka osoba jest najstarsza, 
 * najcięższa oraz najwyższa.
 */

#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    std::string surname;

    int age;
    int weight;
    int height;

    double bmi() const {
        return (double)weight / (height * height);
    }
};

std::vector<Person> people{
    {"Pan", "Kleks", 55, 75, 170},
    {"Jan", "Kowalski", 18, 70, 180},
    {"Janina", "Kowalska", 40, 64, 165},
    {"Sebastian", "Zdun", 16, 73, 182},
};


int main(){

    std::sort(
        people.begin(), 
        people.end(), 
        [](const Person &a, const Person &b){ 
            return a.bmi() < b.bmi(); 
        }
    );

    for(const auto &p : people)
        std::cout << p.name << " "
                  << p.surname << " "
                  << p.age << " "
                  << p.weight << " "
                  << p.height << " "
                  << p.bmi() << std::endl;
    
    auto oldest = std::max_element(
        people.begin(),
        people.end(),
        [](const Person &a, const Person &b){
            return a.age < b.age;
        }
    );
    std::cout << "oldest: " 
              << oldest->name << " " 
              << oldest->surname << std::endl;
    
    auto heaviest = std::max_element(
        people.begin(),
        people.end(),
        [](const Person &a, const Person &b){
            return a.weight < b.weight;
        }
    );
    std::cout << "heaviest: " 
              << heaviest->name << " " 
              << heaviest->surname << std::endl;
    
    auto heighest = std::max_element(
        people.begin(),
        people.end(),
        [](const Person &a, const Person &b){
            return a.height< b.height;
        }
    );
    std::cout << "heighest: " 
              << heighest->name << " " 
              << heighest->surname << std::endl;

    return 0;
}
