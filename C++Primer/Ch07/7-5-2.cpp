#include "..\Ch2\Sales_data.h"
#include <iostream>

int main(){
    Sales_data sd1;

    Sales_data sd2("12345");

    Sales_data sd3(std::cin);

    Sales_data sd4("abcde", 10, 10);
}

//the output is:
/////////// (for the first decleration) ////////////
// ctor with 3 arguments is called      
// the default ctor is called

/////////// (for the second decleration) ////////////
// ctor with 3 arguments is called      
// ctor with a string argument is called

/////////// (for the third decleration) ////////////
// ctor with 3 arguments is called      
// the default ctor is called
// qwert 12 34 (this is the input for argument std::cin)
// ctor with with an istream& argument is called

/////////// (for the last decleration) ////////////
// ctor with 3 arguments is called