#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void elim_dup(vector<int>&);

int main(){
    vector<int> v{5,4,4,4,3,2,1,1,0};
    elim_dup(v);
}

void elim_dup(vector<int>& v){
    sort(v.begin(), v.end());
    for (auto& i : v)
        cout << i << " ";
    
    cout << endl;

    //the elements after end_unique is unknown
    auto end_unique = unique(v.begin(), v.end());
    for(auto& i: v)
        cout << i << " ";

    cout << endl;

    v.erase(end_unique, v.end());
    for(auto& i : v){
        cout << i << " ";
    }
    cout << endl;
}

