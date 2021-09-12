#include <iostream>

class Debug{
    public:
        constexpr Debug(bool a): hardware(a), io(a), other(a){}
        constexpr Debug(bool hw, bool io, bool other): hardware(hw), io(io), other(other){}

    private:
        bool hardware;
        bool io;
        bool other;
};