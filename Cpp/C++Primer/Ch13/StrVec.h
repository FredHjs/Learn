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

        ~StrVec();

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
};

#endif