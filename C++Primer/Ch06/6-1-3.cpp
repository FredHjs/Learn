#include <iostream>
#include "Chapter6.h"
#include "6-1.cpp"

//this is where the program starts (the main() function)
//the three files (header file and two source files) will be compiled separately
int main(){
    unsigned int v{1};
    int v2{0};
    std::cout << "enter a positive integer: ";

    std::cin >> v;

    std::cout << std::endl;
    std::cout << v << "! = " << factorial(v) << std::endl;

    std::cout << "now enter an arbitrary integer: ";
    std::cin >> v2;
    std::cout << std::endl;

    std::cout << "the absolute value of " << v2 << " is " << abs_val(v2);

}