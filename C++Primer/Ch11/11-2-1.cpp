#include <map>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    string last_name, first_name;
    map<string, vector<string>> families;
    char c;

    do
    {
        vector<string> first_names;
        cout << "enter the last name of the family: ";
        cin >> last_name;
        cout << endl;
        cout << "enter the first names: ";
        while (cin >> first_name){
            first_names.push_back(first_name);
        }

        families[last_name] = first_names;
        cout << "do you want to insert another family? (y/n)  ";
        cout << endl;
        
        cin.clear();
        cin >> c; 

    } while (c == 'y');
    
    for (auto family : families){
        cout << family.first << ": ";

        for (auto s : family.second){
            cout << s << " ";
        }

        cout << endl;
    }
}
