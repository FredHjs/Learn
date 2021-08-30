#include <iostream>
#include "Chapter6.h"


//here we define the functions declared in "Chapter6.h", and this file will also be included in
//  the main file (6-1-3.cpp)
int factorial(int value){
    int result{1};
    while (value != 1){
        result *= (value--);
    }

    return result;
}

unsigned int abs_val(int v){
    if (v < 0){
        v = -v;
    }

    return static_cast<unsigned> (v);
}



