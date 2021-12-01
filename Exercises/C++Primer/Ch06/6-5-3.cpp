#include <iostream>
#include <vector>

#define NDEBUG  //defining the marco NDEBUG will disable the cout statement in recursive_vec

using namespace std;

void recursive_vec(vector<int>::size_type start_from, vector<int> v);

int main(){
    vector<int> va = {1,2,3,4,5};

    recursive_vec(0, va);
}

void recursive_vec(vector<int>::size_type start_from, vector<int> v){
    
    #ifndef NDEBUG
    cout << "start from " << start_from << " in this call" << endl;
    #endif
    
    if (start_from != v.size() - 1){
        cout << v[start_from] << endl;
        recursive_vec(++start_from, v);
        return;
    }

    cout << v[start_from] << endl;
    return;
}