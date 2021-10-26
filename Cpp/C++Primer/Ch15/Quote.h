#ifndef QUOTE_H
#define QUOTE_H

#include <string>
using std::string;

class Quote{
    public:
        Quote() = default;

        Quote(const string& s, double price): ISBN(s), unit_price(price){}

        string isbn() const {return ISBN;}

        virtual double net_price(std::size_t num_sold) const {return unit_price * num_sold;}

        virtual ~Quote() = default;

    private:
        string ISBN;

    protected:
        double unit_price;
};

#endif