#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool has_five_char(string&);
int main(){
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"}; 

    auto it = partition(words.begin(), words.end(), has_five_char);

    for (vector<string>::iterator iter{words.begin()}; iter != it; ++iter){
        cout << *iter << " ";
    }
}

bool has_five_char(string& s){
    return s.size() >= 5;
}
