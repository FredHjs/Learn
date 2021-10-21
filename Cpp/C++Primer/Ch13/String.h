#ifndef STRING_H
#define STRING_H
#include <memory>

class String{
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);

    public:
        String() = default;

        String(const char cp[]);

        String(const String&);

        String(String&&) noexcept;

        String& operator=(String&&) noexcept;

        ~String(){free();}

        std::size_t capacity() const {return end - begin;}

    private:
        static std::allocator<char> alloc;

        char* begin;

        char* end;

        void free();
};

#endif