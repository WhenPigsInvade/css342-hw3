#include <iostream>
#include "List342.h"
#include "List342.cpp"

int main() {
    
    List342<int> l1;
    l1.Insert(new int(10));
    l1.Insert(new int(20));
    l1.Insert(new int(30));

    int num1;
    std::cout << l1 << std::endl;

    l1.Remove(20, num1);

    std::cout << l1.Size() << std::endl;
    std::cout << l1 << std::endl;

    
}