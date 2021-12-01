#include <forward_list>
#include <iostream>

using std::forward_list;
using std::string;

void find_and_insert(string, string, forward_list<string>&);

int main(){
    forward_list<string> flist{"abc", "def", "hij", "klm"};

    find_and_insert("qrs", "nop", flist);

    for (auto &s : flist){
        std::cout << s << " ";
    }
}

void find_and_insert(string to_find, string to_insert, forward_list<string>& flist){
    auto prev = flist.before_begin();
    auto curr = flist.begin();
    bool found = false;

    while (curr != flist.end()){
        if (*curr == to_find){
            curr = flist.erase_after(prev);
            flist.insert_after(prev, to_insert);
            found = true;
        }else{
            prev = curr;
            ++curr;
        }
    }

    if (!found){
        flist.insert_after(prev, to_insert);
    }
}