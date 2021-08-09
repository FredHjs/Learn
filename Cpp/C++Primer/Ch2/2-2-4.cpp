#include<iostream>

int reused = 42;

int main(){
    int reused{0};
    int block_scope{reused}; //the block block scope variable overrides the global variable within a func
    int global_scope{::reused}; //visit the global variable by global scope operator ::

    std::cout << reused << " " << block_scope << " " << ::reused << " " << global_scope << std::endl;
    //prints 0 0 42 42
    return 0;
}