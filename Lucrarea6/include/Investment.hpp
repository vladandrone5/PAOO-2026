#pragma once
#include <iostream>
#include <string>

class Investment {
private:
    std::string name;

public:
    explicit Investment(const std::string& n) : name(n) {
        std::cout << "[Investment] Created: " << name << "\n";
    }

    ~Investment() {
        std::cout << "[Investment] Destroyed: " << name << "\n";
    }

    void display() const {
        // TODO: Print the investment's name or details

        std::cout << "[Investment] Name: " << this->name << "\n";
    }
};

// Factory function returning a raw pointer (caller is responsible for deleting it)
inline Investment* createInvestment(const std::string& name) {
    // TODO: Dynamically allocate and return a new Investment object

    return new Investment(name);

    //return nullptr;
}