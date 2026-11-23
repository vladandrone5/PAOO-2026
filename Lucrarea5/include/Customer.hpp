#pragma once
#include <string>

class Customer {
private:
    std::string name;
    // TODO (Item 12 test): Later, try adding a new member (e.g., int lastTransactionId)
    // and remember to update BOTH the copy constructor and copy assignment operator.

public:
    explicit Customer(const std::string& name = "Unknown");
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);
    virtual ~Customer() = default;

    virtual void print() const;
};