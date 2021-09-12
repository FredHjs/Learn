#include <iostream>

class Debug{
    public:
        constexpr Debug(bool a = true): hardware(a), io(a), other(a){}
        constexpr Debug(bool hw, bool io, bool other): hardware(hw), io(io), other(other){}
        constexpr bool any(){return hardware||io||other;}
        void set_io(bool a){io = a;}
        void set_hw(bool a){hardware = a;}
        void set_other(bool a){other = a;}

    private:
        bool hardware;
        bool io;
        bool other;
};

int main(){
    return 0;
}