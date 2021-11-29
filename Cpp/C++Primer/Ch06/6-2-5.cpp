#include <iostream>

//compile this, input '.\6-2-5 hello world' ("hello" "world are the two elements of argv[] in this case")
//      in the command line and the output is "hello \n world"
int main(int argc, char* argv[]){
    for (int i{0}; i < argc; ++i){

        for (char* p_array = argv[i]; *p_array != '\0'; ++p_array){
            std::cout << *p_array;
        }

        std::cout << std::endl;
    }
}