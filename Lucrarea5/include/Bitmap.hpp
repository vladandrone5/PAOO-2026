#pragma once
#include <string>

class Bitmap {
private:
    std::string data;

public:
    explicit Bitmap(const std::string& d = "default") : data(d) {}
    // Copy constructor is compiler-generated and sufficient for std::string
    
    const std::string& getData() const { return data; }
    void setData(const std::string& d) { data = d; }
};