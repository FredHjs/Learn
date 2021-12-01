#include <iostream>
#include <string>
using namespace std;

void replace_by_erase_and_insert(string&, string, string);
int main(){
    string s = "don't know how to do it tho";

    replace_by_erase_and_insert(s, "tho", "though");

    cout << s;
}

void replace_by_erase_and_insert(string& s, string oldVal, string newVal){

   for (auto beg = s.begin(); (s.end() - beg) >= oldVal.size();) {
        if (string{beg, beg + oldVal.size()} == oldVal) {
            beg = s.erase(beg, beg + oldVal.size());
            beg = s.insert(beg, newVal.cbegin(), newVal.cend());
            beg += newVal.size();
        }
        else
            ++beg;
    }
}