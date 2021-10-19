#ifndef STRING_H
#define STRING_H
#include <memory>

class String{
    public:
        String() = default;
        String(const char cp[]);
        String(const String&);
        String(String&&) noexcept;
        String& operator=(String&&) noexcept;

    private:
        static std::allocator<char> alloc;
        char* begin;
        char* end;
        void free();
};

#endif