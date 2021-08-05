# include <iostream>

int main(){
    int lower{};
    int upper{};
    std::cout << "please enter the lower bound: ";
    std::cin >> lower;
    std::cout << "please enter the upper bound: ";
    std::cin >> upper;
    int i{lower + 1};
    while (i < upper){
        std::cout << i;
        i++;
    }

    return 0;
}