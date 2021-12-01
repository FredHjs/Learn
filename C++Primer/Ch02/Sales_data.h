#ifndef SALE_DATA_H
#define SALES_DATA_H
#include <string>
#include <stdexcept>
#include <iostream>

class Sales_data{
    friend std::ostream& print(std::ostream& os, Sales_data sd);
    public:
    //when using delegating ctors, the compiler will first call the delegated ctor, then the calling ctor
        Sales_data(const std::string &s, unsigned n, double p): 
            ISBN(s), num_sold(n), revenue(p*n){
                std::cout << "ctor with 3 arguments is called" << std::endl;
            }
        
        Sales_data(): Sales_data("", 0, 0.0){
            std::cout << "the default ctor is called" << std::endl;
        }
        Sales_data(const std::string &s): Sales_data(s, 0, 0.0){
            std::cout << "ctor with a string argument is called" << std::endl;
        }
        Sales_data(std::istream &is);
        std::string isbn() const {return ISBN;}
        Sales_data& combine(const Sales_data& rhs);
        inline double avg_price() const {return revenue/num_sold;}

    private:
        std::string ISBN;
        int num_sold{0};
        double unit_price{0.0};
        double revenue{0.0};
};

inline Sales_data::Sales_data(std::istream &is): Sales_data(){
    is >> ISBN >> num_sold >> unit_price;
    revenue = num_sold * unit_price;
    std::cout << "ctor with with an istream& argument is called" << std::endl;
}

Sales_data& Sales_data::combine(const Sales_data& rhs){
    if (this->ISBN != rhs.ISBN){
        throw std::runtime_error("not the same book!");
    }

    this->num_sold += rhs.num_sold;
    this->revenue += rhs.revenue;

    return *this;
}

std::ostream& print(std::ostream& os, Sales_data sd){
    os << sd.ISBN + " " << sd.num_sold + " " << sd.unit_price << " " << sd.revenue;
    return os;
}

#endif