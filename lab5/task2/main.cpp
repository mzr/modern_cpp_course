/* Zaprogramuj strukturę danych do przetrzymywania ważonego grafu 
 * dynamicznego w postaci list sąsiadów. Wspomniana dynamiczność 
 * oznacza, że można dodawać nowe a także usuwać istniejące 
 * wierzchołki w grafie. Co się tyczy krawędzi, krawędzie można 
 * dodawać i usuwać, a także zmieniać ich wagę. Wykorzystaj do tego 
 * celu kolekcje standardowe.
 * Każdy wierzchołek grafu niech oprócz kolejnego numeru będzie 
 * miał przypisaną nazwę. Do wierzchołków grafu chcielibyśmy 
 * odwoływać się zarówno poprzez jego numer jak i nazwę.
 * Zaprogramuj też w grafie algorytm sprawdzania czy istnieje 
 * ścieżka pomiędzy zadanymi wierzchołkami.
 */

#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
#include <list>


using namespace std;

// bez multikrawedzi
// jak usuwam wierzcholek to usuwam krawedzie in/out z niego
// jak usunac krawedzie in do niego?
// w wierzcholku nie wiem kto na mnie pokazywal
class Graph {
    
    using vertex_num = int;
    using edge_weight = int;
    using vertex_name = string;
    
    using neighbours = list<vertex_num>;

    using vertex = pair<
        vertex_name,
        neighbours
    >;

    using name_to_num_t = unordered_map<string, vertex_num>;
    using adj_list_t = vector<vertex>;

public:

    name_to_num_t *name_to_num;
    adj_list_t *adj;
    
    Graph() {
        name_to_num = new name_to_num_t();
        adj = new adj_list_t();
    }


    Graph(const Graph &g) {
        name_to_num =              
    }

    vertex_num vertex_name_to_num(vertex_name &s){
        return (*name_to_num)[s];
    }

/*
    Graph& operator=(const Graph &g){
    }

    Graph(Graph &&g){
    }

    Graph& operator=(Graph &&g){
    }

    ~Graph() {
        delete name_to_num;
        delete adj;
    }

*/
};


int main(){


    return 0;
}
