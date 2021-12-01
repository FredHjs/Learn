#include <iostream>
#include <vector>
#include <string>

template<typename...Args> void foo(Args&...args){
    std::cout << sizeof...(Args) << " " << sizeof...(args) << std::endl;
}

int main(){
    int i = 0;
    double d = 6.9;
    char c = '\t';
    bool b = false;
    std::vector<std::string> v = {"hello", "world", "!!!"};

    //prints the number of arguments
    foo(i);
    foo(i, d);
    foo(i, d, c);
    foo(i, d, c, b);
    foo(i, d, c, b, v);
}