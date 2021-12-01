#include <iostream>
#include <vector>

using namespace std;
int main(){
    int temp{};
    vector<int> v1;
    
    while (cin >> temp){
        v1.push_back(temp);
    }

    cout << "size of v1 is " << v1.size() << endl; 
    
    for (auto &i : v1){
        cout << i << "^2 = " << i*i << endl;
    }
}