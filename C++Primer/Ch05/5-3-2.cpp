#include <iostream>

using namespace std;

int main(){
    string s;
    cout << "enter a string: ";

    getline(cin, s);

    int vowel_cnt{0}, empty_cnt{0}, ff_cnt{0}, fl_cnt{0}, fi_cnt{0};
    for (auto it = s.cbegin(); it != s.cend(); ++it){
        char c = tolower(*it);
        switch (c)
        {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            ++vowel_cnt;
            break;

        case ' ': case '\t': case '\n':
            ++empty_cnt;
            break;

        case 'f':
            if (it != (s.cend() - 1)){
                switch (*(it + 1))
                {
                case 'f':
                    ++ff_cnt;
                    break;
                
                case 'l':
                    ++fl_cnt;
                    break;

                case 'i':
                    ++fi_cnt;
                    break;
                
                default:
                    break;
                }
            }else{
                break;
            }
        
        default:
            break;
        }
    }

    cout << "vowel: " << vowel_cnt << endl;
    cout << "empty: " << empty_cnt << endl;
    cout << "ff: " << ff_cnt << endl;
    cout << "fl: " << fl_cnt << endl;
    cout << "fi: " << fi_cnt << endl;

}