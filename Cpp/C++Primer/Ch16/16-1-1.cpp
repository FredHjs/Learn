#include <vector>
#include <list>
#include <iostream>
#include "Vec.h"

template <typename T_Iter, typename T_Val>
T_Iter find(T_Iter iter_beg,T_Iter iter_end, T_Val val){
    while (iter_beg != iter_end){
        if (*iter_beg == val)
            return iter_beg;
        ++iter_beg;
    }
    return iter_end;
}

int main(){
    std::vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    std::list<std::string> li = {"hello", "world", "!!!"};

    std::cout << *find(vi.begin(), vi.end(), 7) << std::endl;
    std::cout << *find(li.begin(), li.end(), "!!!") << std::endl;

    Vec<int> vec{1,2,3,4,5,6};
    std::cout << vec[0] << std::endl;
}