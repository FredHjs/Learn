#ifndef DISCQUOTE_H
#define DISCQUOTE_H

#include "Quote.h"

class DiscQuote : public Quote{
    public:
        DiscQuote() = default;

        DiscQuote(const std::string& s, double price, std::size_t qty, double discount) :
            Quote(s, price), min_qty(qty), discount(discount){}

        DiscQuote(const DiscQuote& rhs): Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount){
            std::cout << "DiscQuote copy ctor" << std::endl;
        }

        DiscQuote& operator=(const DiscQuote&);

        double net_price(std::size_t) const = 0;

    protected:
        std::size_t min_qty;

        double discount;
};

DiscQuote& DiscQuote::operator=(const DiscQuote& rhs){
    std::cout << "DiscQuote operator=()" << std::endl;
    this -> Quote::operator=(rhs);
    min_qty = rhs.min_qty;
    discount = rhs.discount;
    return *this;
}

#endif