#include <iostream>
#include <string>

template <typename T> void size_type_print(T& container){
    //must explicitly tell compiler that T::size_type is a typename instead of a static member of T
    for (typename T::size_type i = 0; i < container.size(); ++i){
        std::cout << container[i] << " ";
    }
}

template <typename T2> void iter_print(T2& container){
    for (typename T2::iterator iter = container.begin(); iter != container.end(); ++iter){
        std::cout << *iter << " ";
    }
}

int main(){
    std::string s = "hello,world";
    size_type_print(s);
    std::cout << std::endl;
    iter_print(s);
}