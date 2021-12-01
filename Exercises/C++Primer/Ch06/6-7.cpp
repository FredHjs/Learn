#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
//method 1: defining out own type for function ptrs
using PF = int (*) (int, int);

int sum(int i, int j);
int sub(int i, int j);
int mul(int i, int j);
int divi(int i, int j);

int main(){
    PF p1 = sum, p2 = sub, p3 = mul, p4 = divi;

    //method 2: using decltype(), but don't forget that the type of a func is dependent on both its 
        //return type and its arguments, and don't forget the * after decltype() because decltype()
        //only gives the function type, not a ptr.
    vector<decltype(sum) (*)> vf{p1, p2, p3, p4}; 

    int i{9}, j{3};
    for (int k{0}; k < vf.size(); ++k){
        cout << vf[k](i, j) << endl;
    }
}

int sum(int i, int j){
    return i + j;
}

int sub(int i, int j){
    return i - j;
}

int mul(int i, int j){
    return i * j;
}

int divi(int i, int j){
    if (j == 0){
        throw range_error("divider can't be 0");
    }

    return i/j;

}