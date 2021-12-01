#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

//as long as the operators << or >> are defined on a type (e.g. cout and cin, respectively), we can 
    //initialize ostream_iterators or istream_iterators on them, respectively
int main(){
    istream_iterator<int> it(cin), eof;
    ostream_iterator<int> oi(cout, " the end");
    vector<int> vi;
    while(it != eof){
        vi.push_back(*it++);
    }

    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), oi);
}