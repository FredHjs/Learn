#include "Sales_data_Ch14.h"

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

std::ostream& operator<<(std::ostream& os,const Sales_data& sd){
    os << sd.ISBN + " " << sd.num_sold + " " << sd.unit_price << " " << sd.revenue;
    return os;
}

std::istream& operator>>(std::istream& is, Sales_data& sd){
    is >> sd.ISBN >> sd.num_sold >> sd.unit_price;

    if (is.good()){
        //need to make sure sd.unit_price is stored successfully
        sd.revenue = sd.num_sold * sd.unit_price;
    }else{
        //the operator>> is responsible for reverting from a possible error
        sd = Sales_data();
        throw std::invalid_argument("Please enter in the format of \"ISBN num_sold unit_price\"!");
    }
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs){
    return lhs.ISBN == rhs.ISBN && lhs.num_sold == rhs.num_sold && lhs.unit_price == rhs.unit_price;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs){
    return !(lhs == rhs);
}