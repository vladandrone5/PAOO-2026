#include "PriorityCustomer.hpp"
#include <iostream>

PriorityCustomer::PriorityCustomer(const std::string& name, int priority)
    : Customer(name), priority(priority) {}

// Item 12: Copy base class part AND derived class members
PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
    // TODO: Invoke the base class copy constructor: Customer(rhs)
    // TODO: Initialize priority from rhs
    : Customer(rhs), priority(rhs.priority)
{}

// Item 10 & Item 12
PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs) {
    // TODO: Explicitly call the base class assignment operator: Customer::operator=(rhs);
    // TODO: Copy the derived class member (priority)
    // TODO: Return *this

    Customer::operator=(rhs);
    priority = rhs.priority;
    return *this;
}

void PriorityCustomer::print() const {
    Customer::print();
    std::cout << " | Priority: " << priority << "\n";
}