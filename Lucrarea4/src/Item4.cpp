#include "Item4.h"
#include <iostream>

// TODO: Implement the constructor using the member initialization list[cite: 8]. 
// Ensure members are listed in the order they are declared in the class (theName, theAddress, numTimesConsulted)[cite: 4].
// Do not use assignments in the constructor body, as that is a two-step process[cite: 3].
ABEntry::ABEntry(const std::string& name, const std::string& address) 
/* TODO: Add member initialization list here */ 
{
    // TODO: Ensure the body is empty or only contains operations that cannot be done in the init list.
}

void FileSystem::printStatus() {
    std::cout << "FileSystem active.\n";
}

// TODO: Implement tfs() by returning a local static FileSystem object[cite: 4, 8].
FileSystem& tfs() {
    // TODO: Create a static FileSystem instance and return it.
}