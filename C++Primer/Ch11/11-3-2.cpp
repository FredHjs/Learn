#include <utility>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int main(){
    string s;
    map<string, string::size_type> word_count;
    set<char> punct{',','.','!', '?'};
    cout << "please enter some sentence: ";

    while (cin >> s){
        if (punct.find(*(s.cend() - 1)) != punct.end()){
            s.erase(s.cend() - 1);
        }
        for (auto& c : s){
            c = tolower(c);
        }

        //below is equivalent to ++word_count[s];
        auto insert_ret = word_count.insert(make_pair(s, 1));

        if (insert_ret.second == false){
            ++insert_ret.first -> second;
        }
    }

    cout << endl;
    for (auto& map : word_count){
        cout << map.first << ": " << map.second << endl;
    }
}