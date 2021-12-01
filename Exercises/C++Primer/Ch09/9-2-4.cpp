#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main(){
    list<int> list = {1,2,3,4,5,6};

    //For containers of different types (e.g. list and vector) or convertable element types 
    //      (e.g. int and double), the only way to initialize one of them as a copy of the other
    //      is to use an iiterator range
    //But for containers with exact same types, we can directly copy one to another.
    vector<double> vector(list.cbegin(), list.cend());

    for(const auto& i : vector){
        cout << i << " ";
    }
}