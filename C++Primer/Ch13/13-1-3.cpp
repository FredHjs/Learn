#include <iostream>
#include <vector>
using namespace std;

struct X{
    //default ctor
    X(){cout << "X()" << endl;}

    //copy ctor
    X(const X&){cout << "X(const X&)" << endl;}
};

void foo(X){
    cout << "void foo(X)" << endl;
}

void boo(X&){
    cout << "void boo(X&)" << endl;
}

int main(){
    //default ctor called
    X x1;

    //default ctor called
    X* px = new X;

    //copy ctor called
    vector<X> vx = {x1};

    //first call copy ctor to copy the argument x1, then process foo(x1)
    foo(x1);

    //no ctor called, processes boo(x1) directly
    boo(x1);
}