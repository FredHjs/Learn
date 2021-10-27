#ifndef DISCQUOTE_H
#define DISCQUOTE_H

#include "Quote.h"

class DiscQuote : public Quote{
    public:
        DiscQuote() = default;

        DiscQuote(const std::string& s, double price, std::size_t qty, double discount) :
            Quote(s, price), min_qty(qty), discount(discount){}

        double net_price(std::size_t) const = 0;

    protected:
        std::size_t min_qty;

        double discount;
};

#endif