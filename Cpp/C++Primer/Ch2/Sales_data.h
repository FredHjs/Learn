#ifndef SALE_DATA_H
#define SALES_DATA_H
#include <string>
#include <stdexcept>
#include <iostream>

struct Sales_data{
    Sales_data() = default;
    Sales_data(const std::string &s): ISBN(s){}
    Sales_data(const std::string &s, unsigned n, double p): 
        ISBN(s), num_sold(n), revenue(p*n){}
    Sales_data(std::istream &is);

    std::string ISBN;
    int num_sold{0};
    double unit_price{0.0};
    double revenue{0.0};

    std::string isbn() const {return ISBN;}
    Sales_data& combine(const Sales_data& rhs);

};

Sales_data::Sales_data(std::istream &is){
    is >> ISBN >> num_sold >> unit_price;
    revenue = num_sold * unit_price;
}

Sales_data& Sales_data::combine(const Sales_data& rhs){
    if (this->ISBN != rhs.ISBN){
        throw std::runtime_error("not the same book!");
    }

    this->num_sold += rhs.num_sold;
    this->revenue += rhs.revenue;

    return *this;
}

#endif