#include <iostream>

int main(){
    //int i{3.14};  this is illegal because initializing variable with {} detects whether ther's a risk of losing precision
    int i_1 = 3.14;
    int i_2(3.14); //initilizing with = and () is usable in this case, but will lose precision
    extern int i; //only declare a variable but not defining (initializing) it;
    std::cout << i_1 << i_2;
    return 0;
}

 
