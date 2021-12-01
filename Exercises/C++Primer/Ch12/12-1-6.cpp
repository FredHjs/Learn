#include <iostream>
#include <fstream>
#include <string>
#include "StrBlob.h"
using namespace std;

int main(){
    ifstream input(".\\12-1-6.txt");
    string s;
    StrBlob strBlob;
    while (getline(input, s)){
        strBlob.push_back(s);
    }
    StrBlobPtr strBlobPtr(strBlob);
    //auto x(strBlob.end());
    for (auto i(strBlob.begin()); i != strBlob.end(); i.incr()){
        cout << i.deref() << endl;
    }
}
