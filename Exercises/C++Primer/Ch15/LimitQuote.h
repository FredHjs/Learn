#ifndef LIMITQUOTE_H
#define LIMITQUOTE_H
#include <iostream>
#include "DiscQuote.h"

class LimitQuote : public DiscQuote{
    public:
        LimitQuote() = default;

        LimitQuote(const std::string& s, double price, std::size_t min_qty, std::size_t max_qty, double discount)
            : DiscQuote(s, price, min_qty, discount), max_qty(max_qty){}

        double net_price(std::size_t) const override; 

        void debug() const override {cout << isbn() << " " << unit_price << " " << max_qty << " " << discount;}

    private:
        std::size_t max_qty;
};

double LimitQuote::net_price(std::size_t n) const {
    if (n < min_qty){
        return unit_price * n;
    }else if (n > max_qty){
        return unit_price * (1 - discount) * max_qty + (n - max_qty) * unit_price;
    }else{
        return unit_price * (1 - discount) * n;
    }
}

#endif