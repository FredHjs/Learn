# include <iostream>

int main(){
    int a{3}, b{0};
    auto x = 4;     //auto type variables must be initialized;

    decltype(a) c = a;      //equivalent to: int c = a;

    //equivalent to: int &d = a;
    decltype((a)) d = a;        //decltype((variable)) gives the reference to the type of the variable
    decltype(b = x) e = a;  //assignment yeilds reference type
   
    ++c;    //c == 4
    std::cout << c << std::endl;
    
    ++d;    //a == 4
    std::cout << d << std::endl;
    
    ++e;    //a == 5
    std::cout << e << std::endl;
}