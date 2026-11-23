#include "Widget.hpp"
#include <iostream>

#define DEBUGG 0

#if DEBUGG == 0
    #include "PriorityCustomer.hpp"
    #include <utility>
#endif

int main() {
    std::cout << "=== Item 10: Return reference to *this ===\n";
    // TODO: Create 3 Widgets (w1, w2, w3)
    // TODO: Test chained assignment: w1 = w2 = w3;
    // TODO: Test compound assignment: (w1 += w2) += w3;
    // TODO: Print widgets to verify results

    Widget w1("W1"), w2("W2"), w3("W3");
    w1 = w2 = w3; // chained assignment
    w1.print();
    w2.print();

    Widget a("A"), b("B"), c("C");
    (a += b) += c; // chained compound assigment
    a.print();

    std::cout << "\n=== Item 11: Handle assignment to self ===\n";
    // TODO: Test direct self-assignment: w1 = w1;
    // TODO: Test indirect self-assignment (e.g., via pointers or references: Widget& ref = w1; w1 = ref;)
    // TODO: Print w1 to verify no crash or corrupted data

    w1 = w1;
    Widget &ref = w1;
    w1 = ref;
    w1.print();

    std::cout << "\n=== Item 12: Copy all parts of an object ===\n";
    // TODO: Create PriorityCustomer pc1("Alice", 5)
    // TODO: Test copy constructor: PriorityCustomer pc2(pc1);
    // TODO: Create PriorityCustomer pc3("Bob", 1) and test copy assignment: pc3 = pc1;
    // TODO: Print pc1, pc2, and pc3 to verify both 'name' (base) and 'priority' (derived) were copied

    PriorityCustomer p1("Name1", 5);
    PriorityCustomer p2(p1);

    PriorityCustomer p3("Name3", 1);
    p3 = p1;

    p1.print();
    p2.print();
    p3.print();

    return 0;
}