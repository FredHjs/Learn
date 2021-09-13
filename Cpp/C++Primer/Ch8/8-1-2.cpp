#include <iostream>
using namespace std;

istream& foo(istream&);

int main(){
    foo(cin);
}

istream& foo(istream& is){
    string s;
    while(is >> s){
        cout << s << " ";
    }
    is.clear();
    return is;
}