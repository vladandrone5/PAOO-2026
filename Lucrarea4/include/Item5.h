#ifndef ITEM5_H
#define ITEM5_H

#include <string>

// Item 5: Know what functions C++ silently writes and calls[cite: 1, 8].
template<typename T>
class NamedObject {
private:
    std::string& nameValue; 
    const T objectValue;    

public:
    // TODO: Implement a constructor that initializes the reference and const members[cite: 6].
    NamedObject(std::string& name, const T& value) 
    /* TODO: Add initialization list for nameValue and objectValue */ 
    {
    }

    // Note: The compiler will not generate the copy assignment operator (operator=) 
    // because nameValue is a reference and objectValue is const[cite: 6, 8].
    // TODO: Write a custom operator= if you intend to allow assignment (p = s)[cite: 6].
};

#endif