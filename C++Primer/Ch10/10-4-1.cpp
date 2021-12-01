#include <iterator>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    list<int> lst1, lst2, lst3;

    copy(vi.begin(), vi.end(), front_inserter(lst1));   //9 8 7 6 5 4 3 2 1 
    copy(vi.begin(), vi.end(), back_inserter(lst2));        //1 2 3 4 5 6 7 8 9 
    copy(vi.begin(), vi.end(), inserter(lst3, lst3.begin()));       //1 2 3 4 5 6 7 8 9
    
    for(auto& i : lst1){
        cout << i << " ";
    }
    cout << endl;

    for(auto& i : lst2){
        cout << i << " ";
    }
    cout << endl;

    for(auto& i : lst3){
        cout << i << " ";
    }
    cout << endl;
}