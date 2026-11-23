#pragma once
#include "Customer.hpp"

class PriorityCustomer : public Customer {
private:
    int priority;

public:
    PriorityCustomer(const std::string& name = "Unknown", int priority = 0);
    PriorityCustomer(const PriorityCustomer& rhs);
    PriorityCustomer& operator=(const PriorityCustomer& rhs);

    void print() const override;
};