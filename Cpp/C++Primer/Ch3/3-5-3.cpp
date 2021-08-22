#include <iostream>

int main(){
    int array_1[5], array_2[5];

    std::cout << "enter the 5 elements of array 1: " << std::endl;
    for (auto &i : array_1){
        std::cin >> i;
    }

    std::cout << "enter the 5 elements of array 2: " << std::endl;
    for (auto &j : array_2){
        std::cin >> j;
    }

    int* p_1 = array_1;
    int* p_2 = array_2;

    while (*p_1 == *p_2 && p_2 != std::end(array_2)){
        p_1++;
        p_2++;
    }

    if (p_2 == std::end(array_2)){
        std::cout << "equal";
    }else{
        std::cout << "not equal";
    }
}