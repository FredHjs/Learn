#include <regex>
#include <iostream>
using namespace std;

int main(){
    /* unless after 'c', otherwise 'i' must appear before 'e'*/
    string pattern = "[^c]ei";
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

    regex r(pattern);
    string words;
    smatch result;
    cout << "enter some words to test: ";
    getline(cin, words);
    if (regex_search(words, result, r)){
        cout << result.str() << endl;
    }

}