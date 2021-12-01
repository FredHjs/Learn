#include <iostream>

int main(){
    int v{0};

    while (v != 42){
        std::cin >> v;
    }

    std::cout << "finally we have 42...";
}