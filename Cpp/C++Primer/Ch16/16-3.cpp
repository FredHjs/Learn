#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/* Rule for overloded template functions: the compiler tries to find the nost specific version */

template <typename T> void debug_rep(const T& s){
    cout << "debug_rep(const T& s) called" << endl;
}

template <typename T> void debug_rep(T* s){
    cout << "debug_rep(T* s) called" << endl;
}

void debug_rep(string& s){
    cout << "debug_rep(string& s) called" << endl;
}

int main(){
    string s("hello"), *ps = &s;
    debug_rep(s);   //debug_rep(string& s) called
    debug_rep(ps);  //debug_rep(T* s) called
    debug_rep("world"); //debug_rep(T* s) called
    debug_rep(std::move(s));    //debug_rep(const T& s) called
}