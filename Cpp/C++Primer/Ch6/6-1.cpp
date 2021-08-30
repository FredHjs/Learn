#include <iostream>

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

