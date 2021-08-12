#ifndef SALE_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data{
    std::string ISBN;
    int num_sold{0};
    double unit_proce{0.0};
};

#endif