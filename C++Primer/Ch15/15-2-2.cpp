#include <iostream>
#include "Quote.h"
#include "BulkQuote.h"

std::ostream& print_total(std::ostream& os, Quote& quote, std::size_t num_sold){
    auto net_price = quote.net_price(num_sold);
    os << quote.isbn() << " " << num_sold << " " << net_price;
    return os;
}

int main(){
    Quote q("12345678", 5);
    BulkQuote bq("87654321", 5, 10, 0.5);

    //calls Quote::net_price
    print_total(std::cout, q, 10);

    std::cout << std::endl;

    //calls BulkQuote::net_price
    print_total(std::cout, bq, 10);
}