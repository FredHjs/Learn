#include <iostream>

using namespace std;

//inline functions will be expanded at the place they're called, so no consumptions of calling the function
inline bool is_shorter(const string& s1, const string& s2){
    return s1.size() < s2.size();
}

int main(){
    const string& s1 = "123456";
    const string& s2 = "12345";

    printf("%d", is_shorter(s1, s2));
}