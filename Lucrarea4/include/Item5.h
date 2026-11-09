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
    NamedObject(std::string& name, const T& value) 
        : nameValue(name),
          objectValue(value)
    {}

};

#endif