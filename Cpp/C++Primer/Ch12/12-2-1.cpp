#include <iostream>
#include <string>
using namespace std;

int main(){
    char s1[5] = "str1";
    char s2[5] = "str2";
    string s3 = "str3";
    string s4 = "str4";
    char* pc12 = new char[10];
    char* pc34 = new char[s3.size() + s4.size()];
    for (size_t i = 0; i < 5; ++i){
        pc12[i] = s1[i];
        pc12[i + 5] = s2[i];
    }

    for (string::size_type i = 0; i < s3.size(); ++i){
        pc34[i] = s3[i];
    }
    for (string::size_type i = 0; i < s4.size(); ++i){
        pc34[i + s3.size()] = s4[i];
    }

    for (char* i = pc12; i < pc12 + 10; ++i){
        cout << *i;
    }
    cout << endl;
    for (char* i = pc34; i < (pc34 + s3.size() + s4.size()); ++i){
        cout << *i;
    }

    delete[] pc12;
    pc12 = nullptr;

    delete[] pc34;
    pc34 = nullptr;
}