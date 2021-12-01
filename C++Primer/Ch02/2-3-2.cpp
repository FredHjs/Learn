#include <iostream>

int main(){
    int array[]{1,2,3,4,5};

    for (int i{0}; i < 5; i++){
        int *p = &array[i];
        *p += 1;
        int *&rp = p;   //pointer is an object, so we can reference it
        std::cout << *p << " " << array[i] << " " << *rp << std::endl;
    }
    
}