#include <iostream>
#include <vector>

using namespace std;

bool prefix(vector<int> &v1, vector<int> &v2);

int main(){
    vector<int> v1{1,2,3,4,5,5};
    vector<int> v2{1,2,3,4,5,5,5,5,5,6};

    if (v1.size() <= v2.size()){
        cout << prefix(v1, v2);
    }else{
        cout << prefix(v2, v1);
    }
}

bool prefix(vector<int> &shorter, vector<int> &longer){
    for (decltype(shorter.size()) i{0}; i < shorter.size(); ++i){
        if (shorter[i] != longer[i]){
            return false;
        }
    }

    return true;
}