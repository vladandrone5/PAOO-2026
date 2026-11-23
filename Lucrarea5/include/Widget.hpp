#pragma once
#include "Bitmap.hpp"
#include <string>

class Widget {
private:
    Bitmap* pb; // Heap-allocated resource[cite: 3]

public:
    explicit Widget(const std::string& bitmapData = "default");
    Widget(const Widget& rhs);
    ~Widget();

    // Item 10 & 11: Copy assignment operator
    Widget& operator=(const Widget& rhs);

    // Item 10: Other assignment operators (e.g., +=) should also return *this
    Widget& operator+=(const Widget& rhs);

    // Optional (C++11): Move assignment operator
    Widget& operator=(Widget&& rhs) noexcept;

    // Helper for the "Copy and Swap" idiom (Item 11)
    void swap(Widget& rhs) noexcept;

    void print() const;
};