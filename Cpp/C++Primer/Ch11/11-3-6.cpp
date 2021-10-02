#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
using namespace std;

map<string, string> build_map(ifstream& map_file);
const string& transform(const string& word, map<string, string>& map);
void word_transform(ifstream& map_file, ifstream& text_file);

int main(){
    ifstream map_file(".\\map_file.txt"), text_file(".\\text_file.txt");
    word_transform(map_file, text_file);
}

map<string, string> build_map(ifstream& map_file){
    map<string, string> transform_map;
    string word, mapped_to;
    while (map_file >> word && getline(map_file, mapped_to)){
        if (mapped_to.size() > 1)
            transform_map[word] = mapped_to.substr(1);
        else throw invalid_argument("No mapping rules found for " + word);
    }

    return transform_map;
}

const string& transform(const string& word, map<string, string>& map){
    if (map.find(word) != map.end())
        return map.find(word) -> second;
    else
        return word;
}

void word_transform(ifstream& map_file, ifstream& text_file){
    map<string, string> map = build_map(map_file);
    string line, word;

    while (getline(text_file, line)){
        istringstream stream(line);
        while (stream >> word){
            cout << transform(word, map) << " ";
        }

        cout << endl;
    }
}