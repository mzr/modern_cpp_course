#include <iostream>

int main(){
    auto str = R"limit(
asdf
\n\nasdfb'"''''''"
"''"")

new line in this raw string.
";
)limit";

    std::cout << str << "\n";

    return 0;
}
