#include <iostream>
#include "List342.h"
// #include "List342.cpp"

int main() {
    
    List342<int> l1;
    // std::cout << l1 << std::endl;
    l1.Insert(new int(10));
    l1.Insert(new int(20));
    l1.Insert(new int(30));

    List342<int> l2;
    // std::cout << l1 << std::endl;
    l2.Insert(new int(10));
    l2.Insert(new int(20));
    l2.Insert(new int(40));

    l1.Merge(l2);
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;

    List342<int> l3;
    l3 = l1;
    l3.Insert(new int(15));
    std::cout << l3 << std::endl;
    std::cout << l1 << std::endl;

    std::cout << l3.Contains(new int(40)) << std::endl;
    std::cout << l3.Contains(new int(55)) << std::endl;

    // l1.DeleteList();
    // std::cout << l1 << std::endl;
}