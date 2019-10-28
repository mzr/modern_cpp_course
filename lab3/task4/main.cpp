/* Zdefinuj szablon funkcji, które przeniesie wartość ze wskazanego
 * obiektu do innego obiektu. Uwzględnij dwa aspekty: po pierwsze
 * obiekt źródłowy może być zadany przez wartość/referencję albo
 * przez wskaźnik (rozróżnij te dwa przypadki za pomocą cechy
 * typowej is_pointer), a po drugie obiekt docelowy ma być wskazany
 * przez referencję niekoniecznie tego samego typu (ustal możliwość
 * konwersji za pomocą cechy typowej is_convertible)
 */

/* obiekt źródłowy może być zadany przez wartość/referencję albo
 * wskaznik. */

#include <type_traits>
#include <iostream>

template<class From, class To>
typename std::enable_if<
    std::is_pointer<From>::value && 
    std::is_convertible<
        From,
        To
    >::value 
>::type
move(To dst, From src){
    std::cout <<"pointer\n";     
    
};

template<class From, class To>
typename std::enable_if<
    !std::is_pointer<From>::value && 
    std::is_convertible<
        From,
        To
    >::value 
>::type
move(To dst, From src){
    std::cout <<"not pointer\n";     

};

class A {};
class B : A {};

class C {};

int main(){
    A *aptr1 = new A();
    A *aptr2 = new A();

    A aval1;
    A aval2;
    A aval3;
    A aval4;

    B *bptr1 = new B();
    B *bptr2 = new B();
    B bval1;

    C *cptr1 = new C();


    A &aref1 = aval3;

    move(aval1, aval2); // not pointer
    move(aval4, aref1); // not pointer
    move(aptr1, aptr2); // pointer

//    move(bptr1, aptr1);

    return 0;
}
