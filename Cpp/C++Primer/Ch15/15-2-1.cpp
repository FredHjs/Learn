#include <iostream>
#include "Quote.h"

std::ostream& print_total(std::ostream& os, Quote& quote, std::size_t num_sold){
    auto net_price = quote.net_price(num_sold);
    os << quote.isbn() << " " << num_sold << " " << net_price;
    return os;
}

int main(){
    Quote q("12345678", 5);
    print_total(std::cout, q, 10);
}