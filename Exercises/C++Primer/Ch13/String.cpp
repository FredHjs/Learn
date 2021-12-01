#include "String.h"
#include <algorithm>
#include <iostream>

//static member variables need to be declared again when compiling seperately
std::allocator<char> String::alloc;

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

char& String::operator[](std::size_t index){
    return begin[index];
}

const char& String::operator[](std::size_t index) const {
    return begin[index];
}

std::ostream& operator<<(std::ostream& os, const String& s){
    auto p_traverse = s.begin;

    while (p_traverse != s.end){
        os << *(p_traverse++);
    }

    return os;
}

bool operator==(const String& lhs, const String& rhs){
    if (lhs.capacity() != rhs.capacity()) return false;

    auto p_traverse_l = lhs.begin, p_traverse_r = rhs.begin;

    while(p_traverse_l != lhs.end && p_traverse_r != rhs.end){
        if (*p_traverse_l++ != *p_traverse_r++) return false;
    }

    return true;
}

bool operator!=(const String& lhs, const String& rhs){
    return !(lhs == rhs);
}