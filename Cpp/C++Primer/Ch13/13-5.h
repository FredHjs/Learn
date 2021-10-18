#include <memory>

class String{
    public:
        String() = default;
        String(const char* cp[]);

    private:
        std::allocator<char> alloc;
        char* begin;
        char* end;
};