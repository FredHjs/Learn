#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s = "this is a -(--------)(-)- test for (stack)";
    unsigned left = 0;

    stack<char> stk;

    for (string::size_type i{0}; i < s.size(); ++i){
        stk.push(s[i]);
        if (s[i] == '('){
            ++left;
        }
        if (left && s[i] == ')'){
            while (stk.top() != '('){
                stk.pop();
            }
            stk.pop();
            stk.push('*');
            --left;\
        }
    }

    string output;
    while (!stk.empty()){
        output.insert(output.cbegin(), stk.top());
        stk.pop();
    }

    cout << output;
}