#ifndef ITEM4_H
#define ITEM4_H

#include <string>

// Item 4: Make sure that objects are initialized before they're used[cite: 1].
class ABEntry {
private:
    std::string theName;
    std::string theAddress;
    int numTimesConsulted;

public:
    ABEntry(const std::string& name, const std::string& address);
};

class FileSystem {
public:
    void printStatus();
};

// Replace non-local statics with a function returning a local static[cite: 4, 8].
FileSystem& tfs();

#endif