/* Napisz program, który wypisze zawartość wskazanego katalogu w 
 * lokalnym systemie plików. Jeśli podany przez użytkownika katalog 
 * nie istnieje, to wypisz taką informację. Wypisując zawartość 
 * katalogu posłuż się iteratorem katalogowym directory_iterator.
 */

#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <unordered_set>

namespace fs = std::filesystem;

int main(int argc, char **argv){
    if(argc <= 1){
        std::cout << "Usage: " << argv[0] << " " << "[DIR_PATH]\n";
        return 1;
    }
    
    try {
        for(const auto &p : fs::directory_iterator(argv[1]))
            std::cout << p.path() << std::endl;
    } catch (fs::filesystem_error &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
