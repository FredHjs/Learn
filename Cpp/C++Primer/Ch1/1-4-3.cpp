# include <iostream>

int main(){
    int val{}, sum{};
    std::cout << "enter a list of numbers, seprated by space, end with end-of-file charactor: " << std::endl;
    while (std::cin >> val){
        sum += val;
    }

    std::cout << sum << std::endl; 
    return 0;
}
