#include <iostream>
#include <initializer_list>

using namespace std;

int sum(initializer_list<int> list);

int main(){
    cout << sum({1,2}) << endl;
    cout << sum({1,2,3}) << endl;
    cout << sum({1,2,3,4}) << endl;
}

int sum(initializer_list<int> list){
    auto res{0};
    for (const &i : list){      //elements of an initializer_list are const, so their references must also be const
        res += i;
    }

    return res;
}