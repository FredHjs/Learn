#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
using std::string;
using std::cout;

class Quote{
    public:
        Quote() = default;

        Quote(const string& s, double price): ISBN(s), unit_price(price){}

        string isbn() const {return ISBN;}

        virtual double net_price(std::size_t num_sold) const {return unit_price * num_sold;}

        virtual void debug() const {cout << ISBN << " " << unit_price;}

        virtual ~Quote() = default;

    private:
        string ISBN;

    protected:
        double unit_price;
};

#endif