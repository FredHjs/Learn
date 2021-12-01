#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <string>
using namespace std;

//void print(ostream& os, const QueryResult& qr);

class QueryResult{
    friend void print(ostream& os, const QueryResult& qr);
    public:
        QueryResult(shared_ptr<vector<string>> f, shared_ptr<set<vector<string>::size_type>> lines, 
            const string& word): file(f), line_nums(lines), word(word){}
            
        set<vector<string>::size_type>::iterator begin() const {return line_nums->begin();}

        set<vector<string>::size_type>::iterator end() const {return line_nums->end();}

        shared_ptr<vector<string>> get_file() const {return file;}

    private:
        shared_ptr<vector<string>> file;
        
        shared_ptr<set<vector<string>::size_type>> line_nums;

        string word;
};

void print(ostream& os, const QueryResult& qr){
    auto count = qr.line_nums->size();
    cout << "The word " << qr.word << " occours " << count << " times. " << endl;

    for (auto& line_num : *(qr.line_nums)){
        cout << '\t' << "(line " << line_num << ") " << (*qr.file)[line_num - 1] << endl;
    }
}

#endif