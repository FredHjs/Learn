#include <iostream>
using namespace std;

int main(){
    char resp{};
    string s1, s2;
    do{
        cout << "please enter two strings: ";
        cin >> s1 >> s2;

        if (s1.size() <= s2.size()){
            cout << s1 << endl;
        }else{
            cout << s2 << endl;
        }

        cout << "do it again? (Y/N)";
        cin >> resp;
    }while(tolower(resp) == 'y');
}