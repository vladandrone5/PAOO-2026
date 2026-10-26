#include "PixelBuffer.h"


PixelBuffer::PixelBuffer(size_t s) {
    size = s;
    data = new int[s]{0};

}

PixelBuffer::~PixelBuffer() {
    
    delete[] data;
}

PixelBuffer::PixelBuffer(const PixelBuffer& other) {
    size = other.size;
    data = new int[other.size];

    for(int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

PixelBuffer::PixelBuffer(PixelBuffer&& other) noexcept {
    size = other.size;
    data = other.data;

    other.data = nullptr;
    other.size = 0;
}

void PixelBuffer::setPixel(size_t index, int value) {
    if(index < size) {
        data[index] = value;
    }
}

void PixelBuffer::print() const {
    for(size_t i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}