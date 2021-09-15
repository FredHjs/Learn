#include <vector>
#include <iostream>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector<int>::iterator find(int, vector<int>::iterator, vector<int>::iterator);
int main(){
    vector<int> v1{1,2,3,4,5,6,7,8,9,10};
    int to_find;
    
    cout << "enter a number to find: ";
    cin >> to_find;

    auto result_it = find(to_find, v1.begin(), v1.end());
    if (result_it != v1.end())
        cout << *result_it << endl;

    else
        cout << "can't find " << to_find;
}

vector<int>::iterator find(int i, vector<int>::iterator begin, vector<int>::iterator end){
    vector<int>::iterator i_traverse = begin;

    while (i_traverse != end){
        if (*i_traverse == i){
            return i_traverse;
        }else{
            ++i_traverse;
        }
    }

    return i_traverse;
}