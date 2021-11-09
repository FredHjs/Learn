#include "SharedPtr.h"
#include <iostream>

int main(){
    auto sp = MakeShared<int>(42);
    std::cout << *sp << std::endl;
}