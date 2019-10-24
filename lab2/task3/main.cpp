#include <memory>
#include <iostream>

class A{
    public:
    int x = 5;
};

auto unique(){
    auto ptr = std::unique_ptr<A>(new A);
    std::cout << ptr.get() << "\n";
    std::cout << ptr->x << "\n";

    return ptr;
}

auto shared(){
    auto ptr = std::shared_ptr<A>(new A);
    std::cout << ptr.get() << "\n";
    std::cout << ptr->x << "\n";

    return ptr;
}

int main(){
    auto ptr = unique();
    std::cout << ptr.get() << "\n";
    std::cout << ptr->x << "\n";

    std::unique_ptr<A> ptr2 = unique();
    
    // ptr = ptr2; // not allowed
    ptr = std::move(ptr2);
   
    std::cout << "shared ptrs\n";

    // now shared
    auto ptr3 = shared();
    std::shared_ptr<A> ptr4{ptr3};
    std::shared_ptr<A> ptr5 = ptr4;
    std::cout << ptr3.get() << "\n";
    std::cout << ptr3->x << "\n";
    std::cout << ptr4.get() << "\n";
    std::cout << ptr4->x << "\n";

    // now weak
    std::cout << "shared ptrs\n";
    std::weak_ptr<A> ptr7;
    {
        std::shared_ptr<A> ptr6 = shared();
        std::cout << ptr6.get() << "\n";
        std::cout << ptr6->x << "\n";
        ptr7 = ptr6;
        std::cout << "is_expired " << ptr7.expired() << "\n";
    }
    std::cout << "is_expired " << ptr7.expired() << "\n";
    auto ptr8 = ptr7.lock(); // shared_ptr pointing to NULL
    std::cout << ptr8.get() << "\n"; // address is NULL
    //std::cout << *ptr8 << "\n"; // segfault
    
    // is pointer pointing to NULL dangling?
    // i dont think so

    return 0;
}
