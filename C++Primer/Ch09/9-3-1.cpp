#include <deque>
#include <list>
#include <iostream>
using namespace std;

int main(){
    list<int> list = {1,2,3,4,5,6,7,8,9,10};
    deque<int> odd;
    deque<int> even;
    for (auto it{list.cbegin()}; it != list.cend(); ++it){
        
        (*it % 2) ? (odd.push_back(*it)) : even.push_back(*it);
    }

    for (const auto& i : odd){
        cout << i << " ";
    }

    cout << endl; 

    for (const auto& i : even){
        cout << i << " ";
    }
}