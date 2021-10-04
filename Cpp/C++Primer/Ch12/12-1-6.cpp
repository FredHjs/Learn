#include <iostream>
#include <fstream>
#include <string>
#include "StrBlob.h"
using namespace std;

int main(){
    ifstream input(".\\12-1-6.txt");
    string s;
    StrBlob strBlob;
    StrBlobPtr strBlobPtr(strBlob);\
    while (getline(input, s)){
        strBlob.push_back(s);
    }

    for (auto i(strBlob.begin()); i != strBlob.end(); i.incr()){

    }
}
