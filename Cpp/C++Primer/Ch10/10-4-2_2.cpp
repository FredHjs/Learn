#include <fstream>
#include <iterator>
#include <iostream>
using namespace std;

int main(){
    ifstream input(".\\in.txt");
    ofstream odd_output(".\\out1.txt"), even_output(".\\out2.txt");
    istream_iterator<int> in_it(input), eof;
    ostream_iterator<int> odd_out_it(odd_output, " "), even_out_it(even_output, "\n");

    while(in_it != eof){
        if (*in_it % 2){
            odd_out_it = *in_it++;      //writes odd number, separated by a space
        }else{
            even_out_it = *in_it++;     //writes even number, separated by an end-of-line character
        }
    }
}