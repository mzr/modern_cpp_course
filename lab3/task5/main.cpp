/* Stwórz macierze o rozmiarach odpowiednio 10×10, 100×100, 
 * 1000×1000 i 10000×10000 i wypełnij je losowymi wartościami z
 * zakrsu od 0.5 do 2.0. Następnie podnieś do kwadratu każdą z tych
 * macierzy mierząc czas wykonania tych operacji za pomocą obiektu
 * duration. Dla małych macierzy powtórz operację wielokrotnie a
 * potem zmierzony czas podziel przez tą wielokrotność. Do pomiaru
 * czasu użyj czasomierzy opartych na zegarze high_resolution_clock.
 */

#include <random>
#include <iostream>
#include <chrono>

double arr10[10][10];
double arr100[100][100];
double arr1000[1000][1000];
double arr10000[10000][10000];
double arr_results[10000][10000];

using namespace std;

void fill_random(double **arr, int n){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.5, 2.0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = dis(gen);
        }
    }
}

void square(double **arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            double tmp = 0;
            for(int k=0; k<n; k++){
                tmp += arr[k][j] * arr[i][k];
            }
            arr[i][j] = tmp;
        }
    }
}

auto square_measure(double **arr, int n){
    auto start = std::chrono::high_resolution_clock::now();

    square(arr, n);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Time: " << diff.count() << "\n";
    return diff;
}

int main(){
    square_measure((double**)arr1000, 1000);

    return 0;
}
