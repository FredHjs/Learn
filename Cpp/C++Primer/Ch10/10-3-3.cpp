#include <iostream>
using namespace std;

int main(){
    int i;
    cout << "please enter a number to decreament: ";
    cin >> i;
    cout << endl;

    //a single & within the capture list means that this lambda implicitly captures a reference
    //when the lambda body contains more than a single return statement, we must to explicitly state
        //the return type, otherwise the return type is seen as void
    auto lambda = [&]() -> bool {if (i == 0) return true; while (i != 0) --i; return false;}; 

    bool b = lambda();
    cout << "i = " << i << endl;    //i should always be 0 here
    cout << (b ? "true" : "false");
}