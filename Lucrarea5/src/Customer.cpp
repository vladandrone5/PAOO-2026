#include "Customer.hpp"
#include <iostream>

Customer::Customer(const std::string& name) : name(name) {}

// Item 12: Copy all local data members
Customer::Customer(const Customer& rhs) 
    : name(rhs.name)
{}

// Item 10 & Item 12
Customer& Customer::operator=(const Customer& rhs) {
    // TODO: Handle self-assignment if needed
    // TODO: Copy all member variables from rhs
    // TODO: Return *this

    if(this != &rhs) {
        name = rhs.name;
    }

    return *this;
}

void Customer::print() const {
    std::cout << "Customer: " << name;
}