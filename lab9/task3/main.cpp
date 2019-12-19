#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <unordered_set>


namespace fs = std::filesystem;

int main(int argc, char **argv){
    if(argc < 3){
        std::cout << "Usage: " 
                  << argv[0] << " " 
                  << "[PATH] "
                  << "[[NAME] ...]"
                  << std::endl;
        return 1;
    }

    std::unordered_set<std::string> names{argv + 2, argv + argc};

    try{

        fs::recursive_directory_iterator rid{
            argv[1],
            fs::directory_options::skip_permission_denied,
        };

        for(const auto &p : rid){
            auto path = p.path();
            auto filename = path.filename();
            if(names.contains(filename)){
                std::cout << fs::canonical(path) << " " 
                          << fs::status(path).permissions() << " "
                          << p.file_size() << std::endl;
                //names.erase(filename);
            }
        }
    } catch (fs::filesystem_error &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
