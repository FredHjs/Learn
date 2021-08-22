#include <iostream>
#include <cstring>
#include <string>

int main(){
    char cs_1[6]{'H', 'e', 'l', 'l', 'o', '\0'};
    std::string s{"world"};
    char cs_2[6];
    //API to convert std::string into C style string
    strcpy(cs_2, s.c_str());

    char cs_3[12];

    strcpy(cs_3, cs_1);
    strcat(cs_3, " ");
    strcat(cs_3, cs_2);

    for (auto &c : cs_3){
        std::cout << c;
    }
}