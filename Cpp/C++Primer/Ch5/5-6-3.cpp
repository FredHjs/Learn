#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
    int i{0}, j{0};

    cout << "enter 2 integers: ";
    cout << endl;

    while (cin >> i >> j){
        try {
            if (j){
                int q = i/j;
                cout << "the quotient is " << q << endl;
                return 0;
            }else{
                throw(range_error("the divider can't be 0!!!"));
        }
        
        }catch(range_error &re){
            char c{};
            cout << re.what() << "\ntry again? enter y/n: ";
            cin >> c;
            if (!c || tolower(c) != 'y'){
                break;
            }
        }
    }
    
    

    
}