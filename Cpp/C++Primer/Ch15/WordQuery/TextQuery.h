#ifndef TEXT_QUERY
#define TEXT_QUERY
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <string>
#include <sstream>
#include <algorithm>
#include "QueryResult.h"
using namespace std;

class QueryResult;

class TextQuery{
    public:
        TextQuery(ifstream& input);
        QueryResult query(const string& word) const;

    private:
        shared_ptr<vector<string>> file;
        map<string, shared_ptr<set<vector<string>::size_type>>> word_map;
};

TextQuery::TextQuery(ifstream& input): file(new vector<string>){
    string line;
    
    while (getline(input, line)){
        file->push_back(line);
        istringstream line_stream(line);
        
        string word;
        while (line_stream >> word){
            auto last_char = word.rbegin();
            if (!isalpha(*last_char)){
                word.erase(last_char.base() - 1);
            }
            auto& line_nums = word_map[word];
            if (!line_nums){
                line_nums.reset(new set<vector<string>::size_type>);
            }

            line_nums->insert(file->size());
        }
    }
}

QueryResult TextQuery::query(const string& word) const {
    auto location = word_map.find(word);
    shared_ptr<set<vector<string>::size_type>> no_data(new set<vector<string>::size_type>);

    if (location == word_map.end()){
        return QueryResult(file, no_data, word);
    }else{
        return QueryResult(file, location->second, word);
    }
}

#endif