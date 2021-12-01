#include <iostream>

using namespace std;

//passing by reference can avoid copying the value of arguments.

//when we don't need to change the argument, declare the parameter to be const
bool contains_capital(const string& s);

void to_lower(string& s);

int main(){
    string s1{"qwerTyui"}, s2{"QWErtyU"};
    cout << contains_capital(s1) << endl;
    to_lower(s2);
    cout << s2 << endl;
}

bool contains_capital(const string& s){
    for (auto &c : s){
        if (isupper(c)){
            return true;
        }
    }

    return false;
}

void to_lower(string& s){
    for (auto &c : s){
        if (isupper(c)){
            c = tolower(c);
        }
    }
}