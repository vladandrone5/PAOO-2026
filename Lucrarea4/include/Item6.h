#ifndef ITEM6_H
#define ITEM6_H

// Item 6: Explicitly disallow the use of compiler generated functions you do not want[cite: 1].
class HomeForSale {
public:
    HomeForSale() = default;
    HomeForSale(const HomeForSale&) = delete;
    HomeForSale& operator = (const HomeForSale&) = delete;

};

#endif