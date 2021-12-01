#ifndef SALES_DATA_CH14_H
#define SALES_DATA_CH14_H
#include <string>
#include <stdexcept>
#include <iostream>

class Sales_data{
    friend std::ostream& print(std::ostream& os, Sales_data sd);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend bool operator!=(const Sales_data&, const Sales_data&);

    public:
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

        //explicit conversion operator must be used explicitly (e.g. static_cast<std::string>(sales_data))
        explicit operator std::string() const;

    private:
        std::string ISBN;

        int num_sold{0};

        double unit_price{0.0};

        double revenue{0.0};
};

#endif