#include <iostream>

int main(){
    const double pi = 3.14;
    double e = 2.7;

    //the reference to a const variable must also be const;
    const double &ref_pi = pi;
    std::cout << ref_pi << std::endl;

    //must use a const pointer to point to a constant (can't modify the constant thru this pointer, 
    //but the address stored in the pointer can change)
    const double *p1 = &pi;     
    
    //this is a constant const pointer, neither the pointer value nor the pointed value can change
    const double *const p2 = &pi;

    //a const pointer can point to a non-const variable, but we can't change the value thru this pointer.
    p1 = &e;
    std::cout << *p1 <<std::endl;       //2.7
    //we can change the variable thru other ways tho
    e++;
    std::cout << *p1 <<std::endl;       //3.7

}