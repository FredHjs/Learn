#include <iostream>
#include <vector>
#include <algorithm>
#include "HasPtr_ValueLike.h"
int main(){
    HasPtr h1("h1", 1), h2("h2", 2), h3("h3", 3);
    std::vector<HasPtr> vh = {h2, h2, h1};
    
    for(auto& h : vh){
        std::cout << h.get_s() << " " << h.get_i() << std::endl;
    }
    
    std::sort(vh.begin(), vh.end());

    for(auto& h : vh){
        std::cout << h.get_s() << " " << h.get_i() << std::endl;
    }
}