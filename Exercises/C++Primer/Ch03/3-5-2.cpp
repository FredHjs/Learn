#include <iostream>
#include <vector>


int main(){
    //size of an array must be a constexpr
    const int a = 10;
    
    int array[a]{};
    std::vector<int> vec{};
    for (int i{0}; i < 10; ++i){
        array[i] = i;

    }
    for (auto i : array){
        vec.push_back(i);

        std::cout << vec[i] << " " << array[i] << std::endl;
    }
}