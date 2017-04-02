#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        list<char> stack;
        map<char, char> paren_pair;
        paren_pair['('] = ')';
        paren_pair['['] = ']';
        paren_pair['{'] = '}';
        for (size_t i = 0; i < s.size(); ++i) {
            if (paren_pair.find(s[i]) != paren_pair.end()) {
                stack.push_back(s[i]);
            }
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (stack.size() <= 0) {
                    return false;
                }
                char left_paren = stack.back();
                stack.pop_back();
                if (paren_pair[left_paren] != s[i]) {
                    return false;
                }
            }
        }
        if (stack.size() > 0) {
            return false;
        }
        else {
            return true;
        }
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
