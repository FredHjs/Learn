#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void elimDumps(vector<string>&);

int main(){
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"}; 
    string::size_type sz{};
    cout << "please enter a size: ";
    cin >> sz;
    
    elimDumps(words);
    auto less_than_sz = stable_partition(words.begin(), words.end(), 
                                    [sz](string& s) -> bool {return s.size() >= sz;});

    auto count = less_than_sz - words.begin();
    cout << count << " words longer than " << sz << endl;

    for_each(words.begin(), less_than_sz, [](string& s) {cout << s << " ";});
}

void elimDumps(vector<string>& v){
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
}