#include <map>
#include <set>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    map<string, string::size_type> word_count;
    set<char> punct{',','.','!', '?'};
    cout << "please enter some sentence: ";
    while (cin >> s){
        //ignore the pubctuations
        if (punct.find(*(s.cend() - 1)) != punct.end()){
            s.erase(s.cend() - 1);
        }
        for (auto& c : s){
            c = tolower(c);
        }

        ++word_count[s];
    }

    cout << endl;
    for (auto& map : word_count){
        cout << map.first << ": " << map.second << endl;
    }
}