#pragma once

#include <iostream>
#include <utility>


class PixelBuffer {
private:
    int* data;
    size_t size;

public:

    PixelBuffer(size_t s); // constructor

    ~PixelBuffer(); // destructor

    PixelBuffer(const PixelBuffer& other); // copy constructor

    PixelBuffer(PixelBuffer&& other) noexcept;

    void setPixel(size_t index, int value);

    void print() const;

};