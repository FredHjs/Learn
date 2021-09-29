#include <utility>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<pair<string, int>> v1, v2, v3;
    char c = 'n';
    do {
        string s;
        int i;

        cout << "enter a string: ";
        cin >> s;
        cin.clear();

        cout << "please enter an int: ";
        cin >> i;
        cin.clear();

        pair<string, int> p1 = make_pair(s, i), p2{s, i}, p3(s, i);
        v1.push_back(p1);
        v2.push_back(p2);
        v3.push_back(p3);

        cout << "enter another pair? (y/n)   ";
        cin >> c;
        cin.clear();
    }while(c == 'y');

    for (auto& p : v1){
        cout << p.first << ": " << p.second << "; ";
    }
    cout << endl;
    for (auto& p : v2){
        cout << p.first << ": " << p.second << "; ";
    }
    cout << endl;
    for (auto& p : v3){
        cout << p.first << ": " << p.second << "; ";
    }
    
}
