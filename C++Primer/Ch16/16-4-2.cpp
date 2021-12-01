#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

template <typename T> string debug_rep(const T& s){
    std::ostringstream stream;
    stream << s;
    return stream.str();
}

template <typename T> string debug_rep(T* s){
    std::ostringstream stream;
    stream << *s;
    return stream.str();
}

string& debug_rep(string& s){
    return s;
}

template<typename T> std::ostream& print(std::ostream& os, const T& last){
    os << last << std::endl;
    return os;
}

template<typename T, typename...Args> std::ostream& print(std::ostream& os, const T& next, const Args&...rest){
    os << next << " ";
    return print(os, rest...);
}

template<typename...Args> std::ostream& errMsg(std::ostream& os, const Args&...args){
    //pattern of packet will be applied to each individual member of the packet
    return print(cout, debug_rep(args)...);
}

int main(){
    int i = 34;
    std::string s = "hello world";
    char c = 'z';
    bool b = false;
    double d = 4.5;
    errMsg(std::cerr, i, s, c, b, d);
}
