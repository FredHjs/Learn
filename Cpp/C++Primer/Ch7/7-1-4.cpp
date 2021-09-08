#include "..\Ch2\Sales_data.h"
#include "Person.h"


int main(){
    Sales_data sd1, sd2("isbn123456"), sd3("qwerty", 5, 10), sd4(cin);
    Person p("Fred", "Shanghai");

    cout << sd1.ISBN + " " << sd1.num_sold + " " << sd1.unit_price << " " << sd1.revenue << " " << endl;
    cout << sd2.ISBN + " " << sd2.num_sold + " " << sd2.unit_price << " " << sd2.revenue << " " << endl;
    cout << sd3.ISBN + " " << sd3.num_sold + " " << sd3.unit_price << " " << sd3.revenue << " " << endl;
    cout << sd4.ISBN + " " << sd4.num_sold + " " << sd4.unit_price << " " << sd4.revenue << " " << endl;

    print(p, cout);
}