#include "..\Ch2\Sales_data.h"
#include "Person.h"


int main(){
    Sales_data sd1, sd2("isbn123456"), sd3("qwerty", 5, 10), sd4(cin);
    Person p("Fred", "Shanghai");

    print(cout, sd1) << endl;
    print(cout, sd2) << endl;
    print(cout, sd3) << endl;
    print(cout, sd4) << endl;
    print(p, cout);
}