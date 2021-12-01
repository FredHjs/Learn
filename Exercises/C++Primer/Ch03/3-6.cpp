#include <iostream>

using namespace std;

int main(){
    int ia[3][4] {
                   {1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12}
                  };
    
    for (int (*p)[4] = ia; p != ia + 3; ++p){
        for (int *q = *p; q != *p + 4; ++q){
            cout << *q << " ";
        }
        cout << endl;
    }


}