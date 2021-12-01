#include <fstream>
#include <vector>
#include <iostream>

using std::ifstream;
using std::string;
using std::vector;

int main(){
    vector<string> vs;
    ifstream input("D:\\Projects\\Learn\\Cpp\\C++Primer\\Ch8\\8-2-1.txt");
    string s;
    while(std::getline(input, s)){
        vs.push_back(s);
    }

    for (auto &s : vs){
        std::cout << s << std::endl;
    }
}