#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

int main(){
    cout << 1.17 << std::setw(12) << endl;
    cout << std::setfill('#') << 1.24 << std::setw(12) << endl;
    cout << std::setfill(' ') << std::setprecision(3) << std::setw(12) <<  1.555 << endl;
    cout << std::hexfloat << std::setprecision(3) << std::setw(12) << 3.14159265368 << std::defaultfloat << endl;
    cout << std::oct << std::setw(12) << 9 << std::dec << endl;
}