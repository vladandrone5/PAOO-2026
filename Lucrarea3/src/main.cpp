
#include <iostream>
#include "PixelBuffer.h"

PixelBuffer generatePixelBuffer() {
    PixelBuffer tmp(3);
    tmp.setPixel(0, 255);
    return tmp;
}

int main(void) {

    std::cout << "1)\n";
    PixelBuffer buffer1(5);
    buffer1.setPixel(0, 100);

    std::cout << "2)Copy constructor: \n";
    // daca nu folosim un copy constructor implementat, buffer2 va avea acelasi pointer pt "data" ca si buffer1

    PixelBuffer buffer2 = buffer1;
    buffer2.setPixel(0, 50); // prin schimbarea lui buffer2 se va schimba si buffer1

    std::cout << "buffer 1: ";
    buffer1.print(); // value ramane 100
    std::cout << "buffer 2: ";
    buffer2.print(); // value e 50

    std::cout << "3) Move constructor: \n";
    PixelBuffer buffer3 = generatePixelBuffer(); // creez un obiect temporar => activeaza move constructor-ul
    std::cout << "buffer 3: ";
    buffer3.print(); // in loc sa aloce memorie suplimentara, preia direct datele obiectului temporar (pointer-ul)

    // destructorul se apeleaza la final si sterge buffer1, buffer2 si buffer3
    // previne un "free dublu"
    return 0;
}