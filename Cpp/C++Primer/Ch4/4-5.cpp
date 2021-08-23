#include <iostream>

int main(){
    //front incremental operator returns the value after modification
    //back incremental operator returns the value before modification, then modify the value
    int i{0}, j{0}, *p = &i;

    int v = i++;
    std::cout << v << " " << i << std::endl;    //0  1

    int g = ++j;
    std::cout << g << " " << j << std::endl;    //1  1

    std::cout << (*p)++ << " " << *p << std::endl;    //1  2
    std::cout << ++*p << " " << *p << std::endl;    //3  3

}