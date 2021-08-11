# include <iostream>

int main(){
    int a{3}, b{4};

    decltype(a) c = a;      //equivalent to: int c = a;

    //equivalent to: int &d = a;
    decltype((a)) d = a;        //decltype((variable)) gives the reference to the type of the variable

    ++c;    //4
    ++d;    //4
    std::cout << c << " " << d <<std::endl;
}