#ifndef BULKQUOTE_H
#define BULKQUOTE_H

#include "DiscQuote.h"
class BulkQuote : public DiscQuote{
    public:
        BulkQuote() = default;

        BulkQuote(const std::string& s, double price, std::size_t qty, double discount)
            : DiscQuote(s, price, qty, discount){}

        BulkQuote(const BulkQuote&);

        BulkQuote& operator=(const BulkQuote&);
        
        double net_price(std::size_t) const override;

        void debug() const override {cout << isbn() << " " << unit_price << " " << min_qty << " " << discount;}
};

double BulkQuote::net_price(std::size_t num_sold) const{
    if (num_sold >= min_qty) return unit_price * (1 - discount) * num_sold;
    else return unit_price * num_sold;
}

BulkQuote::BulkQuote(const BulkQuote& rhs): DiscQuote(rhs) {std::cout << "BulkQuote copy ctor" << std::endl;}

BulkQuote& BulkQuote::operator=(const BulkQuote& rhs){
    std::cout << "BulkQuote operator=()" << std::endl;
    this->DiscQuote::operator=(rhs);
    return *this;
}
#endif