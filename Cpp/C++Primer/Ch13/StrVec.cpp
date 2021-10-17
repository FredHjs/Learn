#include "StrVec.h"
using std::string;

void StrVec::alloc_n_move(std::size_t new_cap){
    auto new_elem = alloc.allocate(new_cap);
    auto new_capacity = new_elem + new_cap;
    auto new_first_free = new_elem;

    for (auto i = elements; i != first_free; ++i){
        alloc.construct(first_free++, std::move(*i));
    }

    free();

    elements = new_elem;
    first_free = new_first_free;
    cap = new_capacity;
}

void StrVec::free(){
    if (elements){
        for (auto i = elements; i != first_free; ++i){
            alloc.destroy(i);
        }

        alloc.deallocate(elements, capacity());

        elements = nullptr;
        first_free = nullptr;
        cap = nullptr;
    }
}

void StrVec::reallocate(){
    std::size_t new_cap = (elements && size()) ? 2 * capacity() : 1;
    alloc_n_move(new_cap);
}

void StrVec::push_back(const string& s){
    check_cap_alloc();
    alloc.construct(first_free++, &s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(string* beg, string* end){
    auto data = alloc.allocate(end - beg);
    return {data, std::uninitialized_copy(beg, end, data)};
}