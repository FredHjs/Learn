#include <iostream>
#include <fstream>

int main(){
    char arr[10];
    std::ifstream input(".\\file.txt");
    while (input){
        /* observation: if more than 10 chars in a line, it reads at most 9 chars 
        and the stream becomes bad (loop terminated) */
        /* also, this is raw way of reading a stream, it reads everything including tabs and spaces */
        input.getline(arr, 10, '\n');   
        std::cout << arr << '\n';
    }
}