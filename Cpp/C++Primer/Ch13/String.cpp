#include "String.h"
#include <algorithm>
#include <iostream>

String::String(const char cp[]){
    std::cout << "copy ctor called" << std::endl;
    auto char_end = cp;
    while(*char_end != '\0'){
        ++char_end;
    }

    ++char_end;

    begin = alloc.allocate(char_end - cp);

    end = std::uninitialized_copy(cp, char_end, begin);
}

String::String(String&& s) noexcept : begin(std::move(s.begin)), end(std::move(s.end)){
    s.begin = s.end = nullptr;
    std::cout << "move ctor called" << std::endl;
}

String& String::operator=(String&& rhs) noexcept {
    if (this != &rhs){
        free();
        begin = std::move(rhs.begin);
        end = std::move(rhs.end);
        rhs.begin = rhs.end = nullptr;
    }

    return *this;
}

String::String(const String& rhs){
    begin = alloc.allocate(rhs.end - rhs.begin);

    end = std::uninitialized_copy(rhs.begin, rhs.end, begin);
}

void String::free(){
    auto end_it = end;
    while (end_it != begin){
        alloc.destroy(--end_it);
    }

    alloc.deallocate(begin, end - begin);
}