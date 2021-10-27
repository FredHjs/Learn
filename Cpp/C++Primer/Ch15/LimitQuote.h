#ifndef LIMITQUOTE_H
#define LIMITQUOTE_H
#include <iostream>
#include "Quote.h"

class LimitQuote : public Quote{
    public:
        LimitQuote() = default;

        LimitQuote(const std::string& s, double price, std::size_t qty, double discount)
            : Quote(s, price), max_qty(qty), discount(discount){}

        double net_price(std::size_t) const override; 

        void debug() const override {cout << isbn() << " " << unit_price << " " << max_qty << " " << discount;}

    private:
        std::size_t max_qty;
        double discount;
};

double LimitQuote::net_price(std::size_t n) const {
    if (n <= max_qty){
        return unit_price * (1 - discount) * n;
    }else{
        return unit_price * (1 - discount) * max_qty + (n - max_qty) * unit_price;
    }
}

#endif