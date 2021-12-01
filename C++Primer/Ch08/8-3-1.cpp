#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ifstream input("D:\\Projects\\Learn\\Cpp\\C++Primer\\Ch8\\8-2-1.txt");
    string s;
    ostringstream size_3, other;
    while (getline(input, s)){
        if (s.size() == 3){
            size_3 << s << " ";
        }else{
            other << s << " ";
        }
    }

    cout << "3 chars: " << size_3.str() << endl;
    cout << "others: " << other.str() << endl;
}
