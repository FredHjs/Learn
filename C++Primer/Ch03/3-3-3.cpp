#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s{};
    vector<string> v1;

    while (cin >> s){
        //cout << s << endl;
        v1.push_back(s);
    }

    for (auto &s : v1){

        for (auto &c : s){
            c = toupper(c);
        }
        cout << s << " ";
    }
}