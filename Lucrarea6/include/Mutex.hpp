#pragma once
#include <iostream>
#include <string>

struct Mutex {
    std::string id;
    bool isLocked = false;
};

// Simulated C API for locking/unlocking a mutex
inline void lock(Mutex* pm) {
    // TODO: Set pm->isLocked = true and print a message showing which mutex was locked

    if(!pm) return;
    pm->isLocked = true;
    std::cout << "[Mutex] Locked: " << pm->id << "\n";
}

inline void unlock(Mutex* pm) {
    // TODO: Set pm->isLocked = false and print a message showing which mutex was unlocked
    // Tip: Check if it's already unlocked to make double-unlock bugs obvious!

    if(!pm) return;
    if(!pm->isLocked) {
        std::cout << "[Mutex] It is already unlocked: " << pm->id << "\n";
        return;
    }

    pm->isLocked = false;
    std::cout << "[Mutext] Unlocked: " << pm->id << "\n";
}