#include <iostream>

int main(){
    //type of reference must be same as that of the referenced object;
    //reference is an alias of the object refered to, it's binded to the object;
    //whenever the reference is given a new value the referenced object changes;
    //visiting the reference is exactly same as visiting the variable;
    //reference is not an object, so it can't be copied.
    //non-const reference can't be binded to literals (e.g. int &r = 10 is illegal)
    int i{19}, &ri = i;
    i = 5;
    ri = 10;

    std::cout << i << " " << ri;
}