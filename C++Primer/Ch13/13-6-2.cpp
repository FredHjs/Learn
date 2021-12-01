#include <vector>
#include <iostream>
#include "String.h"
using std::vector;

int main(){
    vector<String> vs;
    String s1("hello");
    vs.push_back(s1);
    vs.push_back(std::move(s1));
}