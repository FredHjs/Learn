#include <iostream>
using namespace std;

void swap_ptr(const int* &p1, const int* &p2);
void print_array(const int* p_begin, int* p_end);

int main(){
    int i{4}, j{5};
    const int *p1 = &i, *p2 = &j;

    swap_ptr(p1, p2);

    cout << *p1 << " " << *p2 << endl;;   //5 4

    int array[5]{0,1,2,3,4};
    print_array(begin(array), end(array));   //01234
}


//we son't need to change the values pointed to, so the ptrs are declared const
//however we need to change the address stored in the ptrs, so the ptrs are passed by ref
void swap_ptr(const int* &p1, const int* &p2){
    const int* p_temp = p1;
    p1 = p2;
    p2 = p_temp;
}


//this is one way to pass an array: by its starting and ending pointers 
void print_array(const int* p_begin, int* p_end){
    while (p_begin != p_end){
        cout << *(p_begin++);
    }
}