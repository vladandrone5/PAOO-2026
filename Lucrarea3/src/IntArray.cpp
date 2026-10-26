#include "IntArray.h"

IntArray::IntArray(size_t s) : size(s), data(new int[s]{0}) {
    std::cout << "Constructor standard apelat (alocare " << size << "elemente)\n";
}

IntArray::~IntArray() {
    std::cout << "Destructor apelat. Eliberare Heap de la adresa: " << data << "\n";
    delete[] data;
}

IntArray::IntArray(const IntArray &other) : size(other.size), data(new int[other.size]) {
    std::cout << "Copy constructor apelat (deep copy - alocare memorie noua)\n";

    for(size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

}

IntArray::IntArray(IntArray&& other) noexcept : size(other.size), data(other.data) {
    std::cout << "Move Constructor apelat (mutare resurse).\n";
    
    other.size = 0;
    other.data = nullptr;
}

void IntArray::setValue(size_t index, int value) {
    if(index < size) {
        data[index] = value;
    }
    return;
}

void IntArray::printArray() const {
    
    for(size_t i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    return;
}