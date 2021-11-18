#include <fstream>
#include <iostream>
#include <string>

int main(){
    std::fstream fs(".\\seek.txt", std::fstream::ate | std::fstream::in | std::fstream::out);
    if (!fs){
        std::cerr << "failed to open the file.";
        return EXIT_FAILURE;
    }

    std::fstream::pos_type end_mark = fs.tellg();
    std::string line;
    fs.seekg(0, std::fstream::beg);
    std::size_t count = 0;
    
    while(fs && fs.tellg() != end_mark){
        std::getline(fs, line);
        fs.ignore();
        auto cur_mark = fs.tellg();
        fs.seekp(0, std::fstream::end);
        count += line.size() + 1;
        fs << count ;
        fs.seekg(cur_mark);
    }
    fs.seekp(0, std::fstream::end);
    fs << '\n';

    return 0;
}