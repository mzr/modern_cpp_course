/* Stwórz macierze o rozmiarach odpowiednio 10×10, 100×100, 
 * 1000×1000 i 10000×10000 i wypełnij je losowymi wartościami z
 * zakrsu od 0.5 do 2.0. Następnie podnieś do kwadratu każdą z tych
 * macierzy mierząc czas wykonania tych operacji za pomocą obiektu
 * duration. Dla małych macierzy powtórz operację wielokrotnie a
 * potem zmierzony czas podziel przez tą wielokrotność. Do pomiaru
 * czasu użyj czasomierzy opartych na zegarze high_resolution_clock.
 */

#include <random>
#include <future>
#include <iostream>
#include <chrono>
#include <array>
#include <memory>
#include <thread>

using namespace std;

template <size_t N>
using array2d = array<array<double, N>, N>;

template <size_t N>
void fill_random(array2d<N> &arr){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.5, 2.0);

    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr.size(); j++){
            arr[i][j] = dis(gen);
        }
    }
}

template<size_t N>
void fill_random_it(array2d<N> &arr){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.5, 2.0);

    for( auto &subarr : arr){
        for( auto &el : subarr ){
            el = dis(gen);
        }
    }
}

template<size_t N>
void fill_random_it2(shared_ptr<array2d<N>> arr_ptr){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.5, 2.0);

    for( auto &subarr : *arr_ptr){
        for( auto &el : subarr ){
            el = dis(gen);
        }
    }
}

template <size_t N>
auto square_measure(shared_ptr<array2d<N>> arr_ptr){
    auto tmp_arr = make_shared<array2d<N>>();

    auto start = std::chrono::high_resolution_clock::now();

    for(int i=0; i<arr_ptr->size(); i++){
        for(int j=0; j<arr_ptr->size(); j++){
            double tmp = 0;
            for(int k=0; k<arr_ptr->size(); k++){
                tmp += (*arr_ptr)[k][j] * (*arr_ptr)[i][k];
            }
            (*tmp_arr)[i][j] = tmp;
        }
    }

    arr_ptr = move(tmp_arr);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;

    return diff;
}


template<size_t N>
//chrono::duration<double> time(){
auto time(){ // czemu nie moge tu auto w gcc?!?!?! w clang++ dziala
    auto arrptr = make_shared<array2d<N>>();
    fill_random_it2(arrptr);
    auto time_elapsed = square_measure(arrptr);
    return time_elapsed;
}

int main(){
    

    auto a1 = async(std::launch::async, &time<100>);
    auto a2 = async(std::launch::async, &time<100>);
    auto a3 = async(std::launch::async, &time<1000>);
    auto a4 = async(std::launch::async, &time<10000>);


//    a1.wait();
//    a2.wait();
//    a3.wait();
//    a4.wait();

    cout << "10x10: " << a1.get().count() << "\n";
    cout << "100x100: " << a2.get().count() << "\n";
    cout << "1000x1000: " << a3.get().count() << "\n";
    cout << "10000x10000: " << a4.get().count() << "\n";

    return 0;
}
