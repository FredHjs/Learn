#include <iostream>
using namespace std;

void swap_ptr(int* p_1, int* p_2){
    int temp = *p_1;
    *p_1 = *p_2;
    *p_2 = temp;
}

int main(){
    int v1{5}, v2{8}, *p1 = &v1, *p2 = &v2;

    cout << *p1 << " " << *p2 << endl;

    swap_ptr(p1, p2);

    cout << *p1 << " " << *p2 << endl;

}