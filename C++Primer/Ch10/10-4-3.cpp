#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main(){
    vector<int> vi{1,2,3,4,5,6,7,8,0,10};

    auto r_beg{vi.crbegin()}, r_end{vi.crend()};

    auto last_zero_pos = find(r_beg, r_end, 0);
    
    //last_zero_pos.base() returns a normal iterator points next to last_zero_pos
    cout << *last_zero_pos.base() << endl;   

    list<int> lst;

    //since r_beg points to the last element of vi, r_beg+3 will point to the 7th element.
        //similarly, r_end originally points to the "-1"st element, so r_end-2 will point to the second
        //element. On reverse iterators, the operations are also reversed
    copy(r_beg+3, r_end-2, inserter(lst, lst.begin()));

    for(auto& i : lst){
        cout << i << " ";
    }
}