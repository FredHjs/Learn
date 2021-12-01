#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main(){
    int ia[]{0,1,1,2,3,5,8,13,21,55,89};
    list<int> li;
    vector<int> vec;
    for (auto & i : ia){
        li.push_back(i);
    }
    vec.assign(li.cbegin(), li.cend());

    for (list<int>::iterator it{li.begin()}; it != li.end(); ++it){
        if (*it % 2){
            //erase function will return the iterator pointing to the next element after 
                //the one being erased
            it = li.erase(it);   
        }else{
            ++it;
        }
    }

    for (vector<int>::iterator it{vec.begin()}; it != vec.end(); ++it){
        if (*it %2){
            ++it;
        }else{
            it = vec.erase(it);
        }
    }
}