#include <iostream>

using std::string;
int main(){
    string s{"1234 qwer"};
    string punct{"hello, world!"};
    std::cout << s.size() << std::endl;

    for (auto &c : s){
        c = 'X'; 
    }
    for (auto &c : punct){
        if (ispunct(c)){
            c = '\0';
        }
    }
    std::cout << s<< std::endl;
    std::cout << s.size() << std::endl;
    std::cout << punct << std::endl;
}