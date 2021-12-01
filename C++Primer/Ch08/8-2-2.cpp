#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;

    //by default, open a file with "out mode" will clear the data in the file
    //the only way to stop the file from being cleared is applying "app" or "in" mode the same time.
    ofstream o("D:\\Projects\\Learn\\Cpp\\C++Primer\\Ch8\\8-2-1.txt", ofstream::app | ofstream::out);
    while (cin >> s){
        o << s << '\n';
    }
}