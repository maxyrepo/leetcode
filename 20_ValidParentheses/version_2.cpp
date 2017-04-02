#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;

#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};

int main () {
    Solution s;
    cout << s.isValid("]") << endl;
    cout << s.isValid("()") << endl;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([)]") << endl;
}
