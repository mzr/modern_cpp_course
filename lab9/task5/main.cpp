/* Napisz program, który policzy i wypisze sumę wielkości 
 * wszystkich plików we wskazanym katalogu i jego podkatalogach. 
 * Jeśli podany przez użytkownika katalog nie istnieje, to wypisz 
 * taką informację. Analizując zawartość katalogu posłuż się 
 * iteratorem katalogowym directory_iterator.
 */

// recursive_directory_iterator is better for this use case.

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <unordered_set>

namespace fs = std::filesystem;

namespace std {
    template <>
    struct hash<fs::path> {
        std::size_t operator()(const fs::path &path) const {
            return hash_value(path);            }
    };
}

size_t path_size(
        const fs::path &start)
//const std::vector<std::string> &filenames)
{

    size_t size = 0;
    std::vector<fs::path> stack;
    std::unordered_set<fs::path> visited;


    while (!stack.empty()) {
        auto parent = stack[stack.size()-1];
        stack.pop_back();
        visited.insert(parent);

        std::cout << parent << "\n";
        size += file_size(parent);

        for(const auto &child : fs::directory_iterator(parent)){
            if(!visited.contains(child.path()))
                stack.push_back(child.path());
        }
    }
    return size;
}


int main(int argc, char **argv){
    size_t sum_bytes{0};

    auto _size = path_size(fs::path(argv[1]));
    std::cout << _size << "\n";
    
    try{
        fs::recursive_directory_iterator rid{
            argv[1],
            fs::directory_options::skip_permission_denied,
        };

        for(const auto &p : rid){
            if(p.is_regular_file())
                sum_bytes += p.file_size();
        }
    } catch (fs::filesystem_error &e) {
        std::cout << e.what() << std::endl;
        return 1;
    };

    std::cout << sum_bytes << std::endl;




    return 0;
}
