/* Napisz program, który zilustruje problem czytelników i pisarzy 
 * z wykorzystaniem operacji czytania z i pisania do jednego pliku 
 * tekstowego.
 *
 * W swoim programie zdefiniuj klasy Czytelnik, Pisarz i Arbiter 
 * (pisarze i czytelnucy posiadają swoje unikatowe dwucyfrowe 
 * identyfikatory). Czytelnicy co pewien czas (określany na bieżąco 
 * w sposób losowy) czytają plik dane.txt i wyświetlają na 
 * standardowym wyjściu ostatnią zapisaną w pliku liczbę 
 * (poprzedzoną identyfikatorem czytelnika). Natomiast pisarze 
 * dopisują także co jakiś czas (określany na bieżąco w sposób 
 * losowy) do tego pliku losowe liczby naturalne (rozpoczynające 
 * się od identyfikatora pisarza). Z przyczyn oczywistych 
 * czytelnicy mogą działać jednocześnie, natomiast pisarze nie. 
 * Co więcej, działalność pisarza wyklucza w tym czasie także 
 * działalność czytelników. Rolą arbitra jest dopuszczanie w 
 * odpowiedni sposób czytelników i pisarzy do pliku dane.txt.
 *
 * Problem należy rozwiązać na różne sposoby:
 *
 * 1. dopuszczając zagłodzenie pisarzy;
 * 2. dopuszczając zagłodzenie czytelników;
 * 3. nie dopuszczając do zagłodzenia ani czytelników ani pisarzy.
 */


#include <iostream>
#include <shared_mutex>
#include <mutex>
#include <thread>
#include <fstream>

class Arbiter {
    std::shared_mutex mtx;
    std::fstream s;

public:
    Arbiter(const std::string &filename)
    : s{filename, s.in | s.out | s.app | s.ate}
    {}


    void read_last(){
        std::shared_lock lock(mtx);
    }
    
    void append(){
        std::unique_lock lock(mtx);
    }

};

class Base {
public:
    Arbiter &a; // reference member???
    Base(Arbiter &a):a{a}{};
    virtual void run() = 0;
};

class Reader : public Base {
    public:
    Reader(Arbiter &a) : Base(a) {};

    void run(){
        while(1){
            // rand sleep delay
            // sleep
            a.read_last();
        }
    }
};


class Writer : Base {
    public:
    Writer(Arbiter &a) : Base(a) {};

    void run(){
        while(1){
            // rand sleep delay
            // sleep
            a.append();
        }
        
    }
};



int main(){
    Arbiter a{"synchronized_file"};
    Writer w0{a};
    Writer w1{a};

    Reader r0{a};
    Reader r1{a};
    Reader r2{a};
    Reader r3{a};
    


    return 0;
}
