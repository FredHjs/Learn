#include <iostream>
#include <cstring>

int main(){
    char cs_1[6]{'H', 'e', 'l', 'l', 'o', '\0'};
    char cs_2[6]{'w', 'o', 'r', 'l', 'd', '\0'};

    char cs_3[14];

    strcpy(cs_3, cs_1);
    strcat(cs_3, " ");
    strcat(cs_3, cs_2);

    for (auto &c : cs_3){
        std::cout << c;
    }
}