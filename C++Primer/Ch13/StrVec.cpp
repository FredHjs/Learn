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

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const string* beg, const string* end){
    auto data = alloc.allocate(end - beg);
    return {data, std::uninitialized_copy(beg, end, data)};
}

StrVec::StrVec(const StrVec& rhs){
    auto new_data = alloc_n_copy(rhs.elements, rhs.first_free);
    elements = new_data.first;
    first_free = new_data.second;
    cap = first_free;
}

StrVec::StrVec(StrVec&& rhs) noexcept: elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap){
    rhs.cap = rhs.first_free = rhs.elements = nullptr;
}

StrVec::StrVec(std::initializer_list<string> li){
    auto new_data = alloc_n_copy(li.begin(), li.end());
    elements = new_data.first;
    first_free = new_data.second;
    cap = first_free;
}

StrVec& StrVec::operator=(const StrVec& rhs){
    auto new_data = alloc_n_copy(rhs.elements, rhs.first_free);
    free();
    elements = new_data.first;
    first_free = new_data.second;
    cap = first_free;
}

void StrVec::reserve(std::size_t n){
    if (capacity() >= n){
        return;
    }else{
        alloc_n_move(n);
    }
}

void StrVec::resize(std::size_t n, const string& s){
    if (size() < n){
        if (capacity() < n){
            reserve(n * 2);
        }
        for (auto i = size(); i != n; ++i){
            alloc.construct(first_free++, s);
        }
    }else{
        for (auto i = size(); i != n; --i){
            alloc.destroy(--first_free);
        }
    }
}

StrVec& StrVec::operator=(StrVec&& rhs){
    if (this != &rhs){
        this->free();
        this->elements = rhs.elements;
        this->first_free = rhs.first_free;
        this->cap = rhs.cap;
        rhs.cap = rhs.first_free = rhs.elements = nullptr;
    }
    
    return *this;
}

std::string& StrVec::operator[](std::size_t index){
    return elements[index];
}

const std::string& StrVec::operator[](std::size_t index) const {
    return elements[index];
}