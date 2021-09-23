#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<double> v = {1.5, 1.5, 2.5, 3.5};

    //the third argument of function accumulate() must be at least convertable to the type of elements in the container
    cout << accumulate(v.cbegin(), v.cend(), 0);
}