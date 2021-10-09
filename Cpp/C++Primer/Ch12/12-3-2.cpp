#include <iostream>
#include <fstream>
#include "QueryResult.h"
#include "TextQuery.h"
using namespace std;

//The relevant codes (in "QueryResult.h", "TextQuery.h" and this file) are an exercise for Ch12 (STL)
void runQueries(ifstream& in);

int main(){
    ifstream file(".\\word_search_file.txt");
    runQueries(file);
}

void runQueries(ifstream& in){
    TextQuery tq(in);
    while (true){
        string s;
        cout << "enter a word to search or enter q to quit: ";
        if (!(cin >> s) || s == "q"){
            break;
        }else{
            print(cout, tq.query(s));
        }
    }
}