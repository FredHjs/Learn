#include <iostream>
//functions are not allowed to return arrays directly
// four ways to declare a function that returns the pointer or reference to an array
using p_arr_string = string (&)[10];
using namespace std;

string (&func(int arg))[10];        //ref

p_arr_string func1(int arg);        //ref

auto func2(int arg) -> string (*)[10];      //pointer

string arr_s[10];
decltype(arr_s) &func4(int arg);        //ref