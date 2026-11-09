#include "Item4.h"
#include <iostream>

// Do not use assignments in the constructor body, as that is a two-step process[cite: 3].
ABEntry::ABEntry(const std::string& name, const std::string& address)
    : theName(name),
      theAddress(address),
      numTimesConsulted(0)
{}

void FileSystem::printStatus() {
    std::cout << "FileSystem active.\n";
}

FileSystem& tfs() {
    static FileSystem fs;

    return fs;
}