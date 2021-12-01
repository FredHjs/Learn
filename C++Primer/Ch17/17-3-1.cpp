#include <regex>
#include <iostream>
using namespace std;

int main(){
    /* unless after 'c', otherwise 'i' must appear before 'e'*/
    string pattern = "[^c]ei";
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

    regex r(pattern, regex::icase); //ignore case
    string words;
    cout << "enter some words to test: ";
    getline(cin, words);
    
    /* Also useful for cregex, wstrgex and wcregex*/
    for (sregex_iterator it(words.cbegin(), words.cend(), r), it_end; it != it_end; ++it){
        cout << it->str() << endl;
    }
}