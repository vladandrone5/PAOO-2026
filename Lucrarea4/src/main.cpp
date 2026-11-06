#include "Item4.h"
#include "Item5.h"
#include "Item6.h"
#include <iostream>

int main() {
    // --- Testing Item 4 ---
    // TODO: Instantiate an ABEntry object to verify your initialization list compiles.
    // TODO: Call tfs().printStatus() to verify your local static initialization compiles.

    // --- Testing Item 5 ---
    std::string newDog("Persephone");
    std::string oldDog("Satch");
    NamedObject<int> p(newDog, 2);
    NamedObject<int> s(oldDog, 36);
    
    // TODO: Attempt to uncomment the assignment below to observe the compiler error caused by 
    // the un-generated operator= (due to reference and const members)[cite: 6, 8].
    // p = s; 

    // --- Testing Item 6 ---
    HomeForSale h1;
    HomeForSale h2;
    // TODO: Attempt to uncomment the lines below to verify that your '= delete' declarations 
    // correctly trigger a compile-time error ("use of deleted function")[cite: 7].
    // HomeForSale h3(h1); 
    // h1 = h2;            

    return 0;
}