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

namespace fs = std::filesystem;

int main(int argc, char **argv){
    size_t sum_bytes{0};
    
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
