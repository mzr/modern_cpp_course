/* W C++17 nie ma trigraphs
 *
 * TRIGRAPH EQUIVALENT
 * ??=      #
 * ??/      \
 * ??'      ^
 * ??(      [
 * ??)      ]
 * ??!      |
 * ??<      {
 * ??>      }
 * ??-      ~
 *
 * DIGRAPH  EQUIVALENT
 * <:       [
 * :>       ]
 * <%       {
 * %>       }
 * %:       #
 *
 * TOKEN    EQUIVALENT
 * %:%:     ##
 * compl    ~
 * not      !
 * bitand   &
 * bitor    |
 * and      &&
 * or       ||
 * xor      ^
 * and_eq   &=
 * or_eq    |=
 * xor_eq   ^=
 * not_eq   !=
 */


%:include <iostream> // c++2a ok
//??=include <iostream> //c++14 ok, c++17 nie ok

int main(){
    int a = 3 bitand 1; // c++2a ok
    std::cout << a << "\n";
    return 0;
}
