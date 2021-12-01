#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    list<int> li = {0,1,2,3,4,5,6,7,8,9};
    auto iter = li.begin();

    while (iter != li.end()){
        if (*iter % 2){
            iter = li.insert(iter, *iter);

            //since the address of list elements are non-continuous, we can't directly use iter += 2.
            ++iter;
            ++iter;
        }
        else{
            iter = li.erase(iter);
        }
    }
    for (auto& i : li){
        cout << i << " ";
    }
    
}