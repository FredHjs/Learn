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

        Quote(const Quote& rhs): ISBN(rhs.ISBN), unit_price(rhs.unit_price){
            std::cout << "Quote copy ctor" << std::endl;
        }

        Quote& operator=(const Quote&);

        string isbn() const {return ISBN;}

        virtual double net_price(std::size_t num_sold) const {return unit_price * num_sold;}

        virtual void debug() const {cout << ISBN << " " << unit_price;}

        virtual ~Quote() = default;

    private:
        string ISBN;

    protected:
        double unit_price;
};

Quote& Quote::operator=(const Quote& rhs){
    std::cout << "Quote operator=()" << std::endl;
    ISBN = rhs.ISBN;
    unit_price = rhs.unit_price;
    return *this;
}

#endif