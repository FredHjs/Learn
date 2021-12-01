#include <memory>
#include <vector>
#include <iostream>
using namespace std;

vector<int>* regular_allocate();
shared_ptr<vector<int>> shared_allocate();

vector<int>* assign_value(vector<int>*);
shared_ptr<vector<int>> assign_value(shared_ptr<vector<int>>);

void print(vector<int>*);
void print(shared_ptr<vector<int>>);

int main(){
    auto p_regular = regular_allocate();
    auto p_shared = shared_allocate();
    print(assign_value(p_regular));
    print(assign_value(p_shared));
}

vector<int>* regular_allocate(){
    return new vector<int>;
}

shared_ptr<vector<int>> shared_allocate(){
    return make_shared<vector<int>>();
}

vector<int>* assign_value(vector<int>* vec){
    int i;
    cout << "enter the numbers for the regularly allocated vector: ";
    while (cin >> i){
        vec->push_back(i);
    }
    cout << endl;
    cin.clear();
    return vec;
}

shared_ptr<vector<int>> assign_value(shared_ptr<vector<int>> vec){
    int i;
    cout << "enter the numbers for the vector allocated by shared_ptr: ";
    while (cin >> i){
        vec->push_back(i);
    }
    cout << endl;
    cin.clear();
    return vec;
}

void print(vector<int>* vec){
    for (vector<int>::size_type i = 0; i != vec->size(); ++i){
        cout << (*vec)[i] << " ";
    }
    cout << endl;

    delete vec;
    vec = nullptr;
}

void print(shared_ptr<vector<int>> vec){
    for (vector<int>::size_type i = 0; i != vec->size(); ++i){
        cout << (*vec)[i] << " ";
    }
    cout << endl;
}