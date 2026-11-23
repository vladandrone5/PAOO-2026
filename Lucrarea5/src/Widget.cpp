#include "Widget.hpp"
#include <iostream>
#include <utility>

Widget::Widget(const std::string& bitmapData) : pb(new Bitmap(bitmapData)) {}

Widget::Widget(const Widget& rhs) 
    : pb(rhs.pb ? new Bitmap(*rhs.pb) : nullptr)
{}

Widget::~Widget() {
    delete pb;
}

void Widget::swap(Widget& rhs) noexcept {
    std::swap(pb, rhs.pb);
}

// Item 10 & Item 11
Widget& Widget::operator=(const Widget& rhs) {
    // TODO (Item 11): Handle self-assignment safely.
    // Choose one of the three approaches from the lab:
    //   1. Identity test: if (this == &rhs) return *this; (not exception-safe)
    //   2. Careful ordering: save old pointer, allocate new Bitmap, then delete old
    //   3. Copy and swap: create a temporary copy of rhs and swap(*this, temp)

    Widget temp(rhs);
    swap(temp);
    return *this;
}

// Item 10
Widget& Widget::operator+=(const Widget& rhs) {
    // TODO: Combine/append rhs's bitmap data to this->pb's data
    // TODO (Item 10): Return a reference to *this

    if(pb && rhs.pb) {
        pb->setData(pb->getData() + " + " + rhs.pb->getData());
    }

    return *this;
}

// Optional (C++11 Move Assignment)
Widget& Widget::operator=(Widget&& rhs) noexcept {
    // TODO: Check for self-assignment (this != &rhs)
    // TODO: Delete current pb, take ownership of rhs.pb, and set rhs.pb to nullptr
    // TODO (Item 10): Return *this

    if(this != &rhs) {
        delete pb;
        pb = rhs.pb;
        rhs.pb = nullptr;
    }

    return *this;
}

void Widget::print() const {
    if (pb) {
        std::cout << "Widget Bitmap: " << pb->getData() << "\n";
    } else {
        std::cout << "Widget Bitmap: [empty/moved]\n";
    }
}