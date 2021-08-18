#include<iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v1;

    for (int i{0}; i < 10; ++i){
        v1.push_back(i);
    }

    for (auto it{v1.begin()}; it != v1.end(); ++it){
        (*it) *= 2;
    }

    //when we don't need modify the value which the iterator points to, we can declare the iterator to be const
    auto const_it{v1.cbegin()};

    while (const_it != v1.cend()){
        cout << *const_it << " ";
        ++const_it;
    }
}