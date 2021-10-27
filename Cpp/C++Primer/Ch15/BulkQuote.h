#ifndef BULKQUOTE_H
#define BULKQUOTE_H

#include "Quote.h"
class BulkQuote : public Quote{
    public:
        BulkQuote() = default;

        BulkQuote(const std::string& s, double price, std::size_t qty, double discount)
            : Quote(s, price), min_qty(qty), discount(discount){}
        
        double net_price(std::size_t) const override;

        void debug() const override {cout << isbn() << " " << unit_price << " " << min_qty << " " << discount;}
    private:
        std::size_t min_qty;
        double discount;
};

double BulkQuote::net_price(std::size_t num_sold) const{
    if (num_sold >= min_qty) return unit_price * (1 - discount) * num_sold;
    else return unit_price * num_sold;
}

#endif