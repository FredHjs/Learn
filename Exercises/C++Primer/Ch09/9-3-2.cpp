#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec = {1,2,3,4,5,6};
    //all the methods below can visit the first element of vec. Not using vec.at(n) is range safe
        //because it throws out_of_range error if n is correct
    std::cout << vec[0] << vec.at(0) << vec.front() << *vec.begin();
}