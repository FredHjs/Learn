#include <list>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<string> v;
    list<char*> list = {"hello", "world", "!!!"};

    v.assign(list.cbegin(), list.cend());

    for (vector<string>::size_type i{0}; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}