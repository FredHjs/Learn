#include <functional>
#include <map>
#include <string>
#include <iostream>
using namespace std;

struct Minus{
    public:
       int operator()(int i, int j){return i - j;}
};

int add(int i, int j){
    return i + j;
}

int main(){
    auto p_add = &add;
    Minus minus;
    auto lambda_mod = [](int i, int j)->int{return i % j;};

    map<char, function<int(int, int)>> func_map{
        {'+', p_add},
        {'-', minus},
        {'*', [](int i, int j)->int {return i * j;}},
        {'/', divides<int>()},
        {'%', lambda_mod}
    };

    //istringstream expression;
    int lhs, rhs;
    char sign;
    cout << "enter a binary expression of int: ";
    cin >> lhs >> sign >> rhs;
    cout << func_map.find(sign)->second(lhs, rhs);

}