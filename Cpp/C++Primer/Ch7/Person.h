#include <iostream>
using namespace std;
struct Person{
    string Name;
    string Address;

    //functions defined inside struct will be seen as inline functions
    string get_name() const {return Name;}
    string get_address() const {return Address;}
};