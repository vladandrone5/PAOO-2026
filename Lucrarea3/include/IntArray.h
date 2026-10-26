#pragma once

#include <iostream>

class IntArray {
private:
    int *data;
    size_t size;

public:

    IntArray(size_t size);

    ~IntArray();

    IntArray(const IntArray &other);

    IntArray(IntArray &&other) noexcept;

    void setValue(size_t index, int value);
    void printArray() const;

};