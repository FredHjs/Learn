#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s, repeat_word, final_word;
    vector<string> vs;
    int repeat_cnt{0}, highest_cnt{0};
    cout << "enter a string of words: ";

    while (cin >> s){
        vs.push_back(s);
    }
    
    auto it = vs.cbegin();
    repeat_word = vs[0];

    while (it != (vs.cend() - 1)){
        if (*(it + 1) == repeat_word){
            ++repeat_cnt;
        }else{
            if (repeat_cnt > highest_cnt){
                final_word = repeat_word;
                highest_cnt = repeat_cnt + 1;
            }

            repeat_word = *(it + 1);
            repeat_cnt = 0;
        }
        ++it;

    }

    if (!highest_cnt){      //when highest_cnt == 0
        cout << "no repeat words";
    }else{
        cout << final_word << " " << highest_cnt;
    }
    

}