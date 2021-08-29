#include <iostream>

int factorial(int value){
    int result{1};
    while (value != 1){
        result *= (value--);
    }

    return result;
}

int main(){
    unsigned int v{1};
    std::cout << "enter a positive integer: ";

    std::cin >> v;

    std::cout << std::endl;
    std::cout << v << "! = " << factorial(v); 

}

