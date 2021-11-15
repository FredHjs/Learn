#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
#include <random>
#include <vector>
using namespace std;

map<string, vector<string>> build_map(ifstream& map_file);
const string& transform(const string& word, map<string, string>& map);
void word_transform(ifstream& map_file, ifstream& text_file);

int main(){
    ifstream map_file(".\\map_file.txt"), text_file(".\\text_file.txt");
    word_transform(map_file, text_file);
}

map<string, vector<string>> build_map(ifstream& map_file){
    map<string, vector<string>> transform_map;
    string word, mapped_to, mapped_word;
    while (map_file >> word && getline(map_file, mapped_to)){
        if (mapped_to.size() > 1){
            istringstream is(mapped_to);
            
            while(is >> mapped_word){
                transform_map[word].push_back(mapped_word);
            }
        }else{
            throw invalid_argument("No mapping rules found for " + word);
        } 
    }

    return transform_map;
}

const string& transform(const string& word, map<string, vector<string>>& map){
    static default_random_engine e;
    
    if (map.find(word) != map.end()){
        uniform_int_distribution<int> u(0,(map.find(word)->second).size() - 1);
        return (map.find(word) -> second)[u(e)];
    }else
        return word;
}

void word_transform(ifstream& map_file, ifstream& text_file){
    map<string, vector<string>> map = build_map(map_file);
    string line, word;

    while (getline(text_file, line)){
        istringstream stream(line);
        while (stream >> word){
            cout << transform(word, map) << " ";
        }

        cout << endl;
    }
}