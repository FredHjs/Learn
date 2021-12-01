#include "SharedPtr.h"
#include <iostream>
#include <string>

int main(){
    auto sp = MakeShared<int>(42);
    std::cout << *sp << std::endl;

    auto sp_2 = MakeShared<std::string>(10, 'c');
    std::cout << *sp_2 << std::endl;
}