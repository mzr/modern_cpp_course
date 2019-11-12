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


using namespace std;

// bez multikrawedzi
// jak usuwam wierzcholek to usuwam krawedzie in/out z niego
// jak usunac krawedzie in do niego?
// w wierzcholku nie wiem kto na mnie pokazywal
class Graph {
    
    using vertex_num = int;
    using edge_weight = int;
    using vertex_name string;
    
    template <typename T, typename K>
    using um = unordered_map<T, K>; 

    using vertex = pair<
        vertex_name*, // * or & ?
        um<vertex_num, edge_weight>
    >;
    // name? ptr to name_to_num_map?

    using adj_map = unordered_map<int, vertex>;
    using name_to_num_map = unordered_map<string, vertex_num>;

    name_to_num_map *name_to_num;
    adj_map *adj;
    
public:
    
    Graph() {
        name_to_num = new name_to_num_map();
        adj = new adj_map();
    }

    add_vertex(

    Graph(const Graph &g) {
        name_to_num = g.name_to_num;
        adj = g.adj;
    }

    Graph& operator=(const Graph &g){
        name_to_num = g.name_to_num;
        adj = g.adj;
        return *this;
    }

    Graph(Graph &&g){
        name_to_num = move(g.name_to_num);
        adj = move(g.adj);
    }

    Graph& operator=(Graph &&g){
        name_to_num = move(g.name_to_num);
        adj = move(g.adj);
        return *this;
    }

    ~Graph() {
        delete name_to_num;
        delete adj;
    }


};


int main(){



    return 0;
}
