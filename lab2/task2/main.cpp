/* Zdefiniuj klasę opakowującą plik tekstowy line_writer. 
 *
 * Obiekt takiej klasy ma przetrzymywać wskaźnik/referencję do 
 * strumienia plikowego ofstream. Zadaniem obiektów tej klasy 
 * będzie pisanie do pliku wiersz po wierszu. Czy klasa ta powinna 
 * zamykać strumień w destruktorze?
 *
 * Dalej w programie głównym stwórz kilka wskaźników shared_ptr do 
 * takiego pliku - niech każdy fragment programu posiadający taki 
 * własny wskaźnik zapisze w tym pliku swoje dane. Plik powinien 
 * zostać zamknięty, gdy wszystkie sprytne wskaźniki zostaną 
 * zlikwidowane.
 */

#include <iostream>
#include <memory>
#include <fstream>

using namespace std;

class line_writer{
    private:
        ofstream *outfile;

    public:

    line_writer(const std::string &fname){
        cout << "line_writer constructor\n";
        outfile = new ofstream(fname, ios::app | ios::out);
    }


    friend line_writer & operator<<(line_writer &o, const string &s);

    ~line_writer(){
        delete outfile;
        cout << "line_writer destructor\n";
    }

};

line_writer & operator<<(line_writer &o, const string &s){
    *o.outfile << s << endl;
    return o;
}

void write_to_file(){
    auto x = make_shared<line_writer>("file.cos");
    auto y = x;
    auto z = y;

    cout << x.use_count() << "\n";

    *x << "abcd" << "efgh";
}

int main(){
    
    write_to_file();

    return 0;
}
