#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::size_t;

template<typename T> size_t occour_times(vector<T> v, const T& val){
        size_t ret = 0;
        for (auto& t : v){
            if (t == val)
                ++ret;
        }
        return ret;
}

template<> size_t occour_times(vector<const char*> v, const char* const& val){
    size_t ret = 0;
        for (auto& t : v){
            if (string(t) == string(val))
                ++ret;
        }
        return ret;
}

int main(){
    vector<int> vi{1,2,3,4,5,6,7,8,8,9,9,9,9,0};
    vector<const char*> vc{"hello", "world", "my name's", "xxx", "xxx", "xxx", "xxx", "!!!"};
    const char c[4] = "xxx";
    cout << occour_times(vi, 8) << " " << occour_times(vc, std::begin(c));
}