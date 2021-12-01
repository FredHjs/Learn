#include <list>
#include <iostream>
using namespace std;

void elim_dup(list<int>& lst);
int main(){

    list<int> l = {1,2,3,4,4,5,6,6,6,6,7,8,9,9,0};
    elim_dup(l);
}

void elim_dup(list<int>& lst){
    lst.sort();

    //member functions of list and forward_list will directly change the container, for example, 
        //this unique() function will delete all the duplicated elements
    lst.unique();   

    for(auto i{lst.begin()}; i != lst.end(); ++i){
        cout << *i << " ";
    }
}