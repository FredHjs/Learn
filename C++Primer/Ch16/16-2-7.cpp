#include <utility>
#include <iostream>

template <typename F, typename T1, typename T2>
void flip(F func, T1&& t1, T2&& t2){
    
    /* std::forward will forward the argument while keeping all its type info, such as l/r-value reference,
    const rpoperties, etc.*/
    func(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f1(int& v1, int&& v2){
    /* some operations...*/
}

void f2(int&& v1, int& v2){
    /* some operations...*/
}

int main(){
    int i = 0, &j = i;
    flip(f1, 23, i);
    flip(f2, j, std::move(i));
}