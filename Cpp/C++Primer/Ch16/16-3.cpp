#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/* Rule for overloded template functions: the compiler tries to find the nost specific version */

template <typename T> string debug_rep(const T& s){
    cout << "debug_rep(const T& s) called" << endl;
    std::ostringstream stream;
    stream << s;
    return stream.str();
}

template <typename T> string debug_rep(T* s){
    cout << "debug_rep(T* s) called" << endl;
    std::ostringstream stream;
    stream << *s;
    return stream.str();
}

string& debug_rep(string& s){
    cout << "debug_rep(string& s) called" << endl;
    return s;
}

int main(){
    string s("hello"), *ps = &s;
    debug_rep(s);   //debug_rep(string& s) called
    debug_rep(ps);  //debug_rep(T* s) called
    debug_rep("world"); //debug_rep(T* s) called
    debug_rep(std::move(s));    //debug_rep(const T& s) called
}