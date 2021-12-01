#include <iostream>
#include <string>

template<typename T> std::ostream& print(std::ostream& os, const T& last){
    os << last << std::endl;
    return os;
}

template<typename T, typename...Args> std::ostream& print(std::ostream& os, const T& next, const Args&...rest){
    os << next << " ";
    return print(os, rest...);
}

int main(){
    int i = 34;
    std::string s = "hello world";
    char c = 'z';
    bool b = false;
    double d = 4.5;
    print(std::cout, c);
    print(std::cout, i, s);
    print(std::cout, i, s, c, b, d);
}