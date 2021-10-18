#include "13-5.h"
#include <algorithm>

String::String(const char* cp[]){
    auto char_end = cp;
    while(char_end){
        ++char_end;
    }

    begin = alloc.allocate(char_end - cp);

    end = std::uninitialized_copy(cp, char_end, begin);
}