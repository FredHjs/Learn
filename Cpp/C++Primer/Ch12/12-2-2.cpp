#include <string>
#include <memory>
#include <iostream>
using namespace std;

int main(){
    allocator<string> alloc;
    size_t n{0};
    cout << "enter the num of string to allocate: ";
    cin >> n;
    cout << endl;
    cin.clear();

    auto p = alloc.allocate(n);
    
    cout << "enter the strings: ";
    string* q = p, s;
    while (cin >> s && q < p + n){
        alloc.construct(q++, s);
    }

    cout << endl;
    cin.clear();
    size_t size = q - p;
    for (size_t i{0}; i < size; ++i){
        cout << *(p+i) << endl;
    }

    for (size_t i{0}; i < size; ++i){
        alloc.destroy(p+i);
        
    }

    cout << "the constructed strings are all destroyed." << endl;

    alloc.deallocate(p, n);

    cout << "the allocator is deallocated." << endl;
}