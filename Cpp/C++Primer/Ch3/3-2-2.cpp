#include<iostream>
#include<string>

using namespace std;

int main(){
    string s1, s2;
    //std::getline(basic_istream, basic_string) assigns the string of the value in istream before an end-of-line char;
    getline(cin, s1);       
    getline(cin, s2);

    //1. if two strings are equally long and contains exactly same chars, then they are equal
    //2. if two strings are different on some positions, then the result is the from the first 
    //   different char (in dictionary order, and capitalization matters)
    //3. null character is smaller than any other chars
    if (s1 > s2){
        cout << "s1 > s2";
    }else if(s1 < s2){
        cout << "s1 < s2";
    }else{
        cout << "s1 = s2";
    }

    cout << endl;
    cout << endl;

    //concate two strings using + operator
    string s3 = s1 + s2;        //must ensure the lvalue is a string object (not a literal)
    cout << s3;
}


