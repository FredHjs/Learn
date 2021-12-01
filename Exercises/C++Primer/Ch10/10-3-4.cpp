#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

bool check_size(const string&, string::size_type);
ostream& print (ostream&, int);
int main(){
    string::size_type sz;
    string s;
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    cout << "enter a string: ";
    cin >> s;
    cout << endl;

    auto longer = find_if_not(v.begin(), v.end(), bind(check_size, s, placeholders::_1));
    cout << *longer;

    cout << endl;

    //when passing reference as an argument to bind(), we should use STL functions ref() or cref()
    for_each(v.cbegin(), v.cend(), bind(print, ref(cout), placeholders::_1));
}

bool check_size(const string& s, string::size_type sz){
    return s.size() >= sz;
}

ostream& print (ostream& os, int i){
    os << i << " ";
    return os;
}