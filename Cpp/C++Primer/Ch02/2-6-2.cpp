#include <iostream>
#include "Sales_data.h"

int main(){
    Sales_data s1, s2;

    std::cout << "info of first item: ";
    std::cin >> s1.ISBN >> s1.num_sold >> s1.unit_proce;
    std::cout << std::endl;

    std::cout << "info of second item: ";
    std::cin >> s2.ISBN >> s2.num_sold >> s2.unit_proce;
    std::cout << std::endl;

    if (s1.ISBN == s2.ISBN){
        std::cout << "the total revenue is " << (s1.num_sold*s1.unit_proce) + (s2.num_sold*s2.unit_proce);
    }else{
        std::cout << s1.ISBN << ": " << s1.num_sold*s1.unit_proce << std::endl;
        std::cout << s2.ISBN << ": " << s2.num_sold*s2.unit_proce << std::endl;
    }
}