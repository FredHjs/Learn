#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <utility>
#include <memory>
#include <initializer_list>

class StrVec{
    public:
        StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr){}

        StrVec(std::initializer_list<std::string>);

        StrVec(const StrVec&);

        StrVec& operator=(const StrVec& rhs);

        ~StrVec(){free();}

        void push_back(const std::string&);

        std::size_t size(){return first_free - elements;}

        std::size_t capacity(){return cap - elements;}

        std::string* begin(){return elements;}

        std::string* end(){return first_free;}

        void reserve(std::size_t);

        void resize(std::size_t);

    private:
        static std::allocator<std::string> alloc;

        std::string* elements;

        std::string* first_free;

        std::string* cap;

        std::pair<std::string*, std::string*> alloc_n_copy(std::string*, std::string*);

        void alloc_n_move(std::size_t new_cap);

        void check_cap_alloc(){if (first_free == cap) reallocate();}

        void reallocate();

        void free();
};

#endif