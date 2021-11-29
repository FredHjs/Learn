#include <iostream>

using namespace std;

int main(){
    int i{6};
    double j{1.50};

    cout << i/j << endl; //i is being converted to double
    
    j = static_cast<int> (j);   //here j is casted to int, everything after decimal point is thrown away

    std::cout << i/j << endl;

    char c{'a'};
    const char *pc = &c;

    char* pc_2 = const_cast<char*>(pc); //now pc and pc_2 points to non-const value

    *pc_2 = 'b';  //we are allowed to change the value of c now

    cout << *pc << endl;


}