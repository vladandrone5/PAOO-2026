#include <iostream>
#include <memory>
#include "Investment.hpp"
#include "Mutex.hpp"
#include "ResourceManagers.hpp"

void demoItem13_ManualLeak() {
    std::cout << "\n--- Item 13: Manual Management (Risk of Leak) ---\n";
    // TODO: Call createInvestment("Manual")
    // TODO: Simulate an early return or throw an exception before `delete` is reached

    try {
        Investment *pInv = createInvestment("Inv");
        pInv->display();

        throw std::runtime_error("\"Fake\" error before delete");

        delete pInv; // memory leak
    } catch(const std::exception& e) {
        std::cout << e.what();
    }
}

void demoItem13_UniquePtr() {
    std::cout << "\n--- Item 13: std::unique_ptr (Single Owner) ---\n";
    // TODO: Create a std::unique_ptr<Investment> using createInvestment() or std::make_unique
    // TODO: Demonstrate that copying fails to compile (leave it commented out)
    // TODO: Transfer ownership to a second unique_ptr using std::move()
    // TODO: Verify the first pointer is now nullptr

    std::unique_ptr<Investment> p1(createInvestment("Unique_Stock"));
    p1->display();

    std::unique_ptr<Investment> p2 = std::move(p1);
    std::cout << "p1 is now: " << (p1 == nullptr ? "nullptr" : "valid") << "\n";
    
    if(p2) {
        p2->display();
    }

    // p2 goes out of scope => investment is destroyed
}

void demoItem13_SharedPtr() {
    std::cout << "\n--- Item 13: std::shared_ptr (Shared Ownership) ---\n";
    // TODO: Create a std::shared_ptr<Investment> using std::make_shared
    // TODO: Copy it to a second shared_ptr and print use_count()
    // TODO: Let one go out of scope (use a nested { } block) and print use_count() again

    auto s1 = std::make_shared<Investment>("Shared_Bond");
    std::cout << "s1 use_count: " << s1.use_count() << "\n";
    {

        auto s2 = s1;
        std::cout << "Inside block -> s1 use_count: " << s1.use_count() << "\n";
        s2->display();
    } // s2 destroyed

    std::cout << "After block -> s1 use_count: " << s1.use_count() << "\n";
}

void demoItem14_Strategies() {
    std::cout << "\n--- Item 14: Copying Behavior in RAII Classes ---\n";
    Mutex m1{"Mutex_1"};
    Mutex m2{"Mutex_2"};
    Mutex m3{"Mutex_3"};

    // 1. Prohibit copying
    std::cout << "\n[Strategy1: prohibit copy]\n";
    {
        // TODO: Instantiate LockNoCopy with &m1
        // TODO: Show that copying it is prevented (commented-out line)
        LockNoCopy l1(&m1);
    }

    // 2. Reference-count
    std::cout << "\n[Strategy2: reference-count]\n";
    {
        // TODO: Instantiate LockRefCount l1(&m2)
        // TODO: Copy l1 to l2 inside a nested scope and print getRefCount()
        // TODO: Verify m2 is only unlocked once, when the last copy is destroyed
        LockRefCount l1(&m2);
        std::cout << "Ref count: " << l1.getRefCount() << "\n";
        {
            LockRefCount l2(l1);
            std::cout << "Ref count after copy: " << l1.getRefCount() << "\n";
        }
        std::cout << "Ref count after inner scope: " << l1.getRefCount() << "\n";
    }

    // 3. Deep copy
    std::cout << "\n[Strategy3: deep-copy]\n";
    {
        // TODO: Create BufferDeepCopy b1("Hello RAII") and copy it to b2
        // TODO: Print both and verify no double-free occurs at the end of the scope
        BufferDeepCopy b1("Hello RAII");
        BufferDeepCopy b2 = b1;
        b1.print();
        b2.print();
    } // no double free necessary

    // 4. Transfer ownership
    std::cout << "\n[Strategy4: transfer ownership]\n";
    {
        // TODO: Instantiate LockTransfer t1(&m3)
        // TODO: Move t1 into t2 using std::move()
        // TODO: Verify m3 is only unlocked once
        LockTransfer t1(&m3);
        LockTransfer t2 = std::move(t1);
    } // t2 unlocks m3
}

int main() {
    demoItem13_ManualLeak();
    demoItem13_UniquePtr();
    demoItem13_SharedPtr();
    demoItem14_Strategies();

    return 0;
}