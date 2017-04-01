#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
int pos;
int max_len;
public:

    void extend(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        ++l;
        --r;
        int len = r - l + 1;
        if (len > max_len) {
            max_len = len;
            pos = l;
        }
        
    }

    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }
    
        pos = 0;
        max_len = 0;
        for(int i = 0; i < s.size(); i++) {
            extend(s, i, i);
            extend(s, i, i+1);
        }

        return s.substr(pos, max_len);
    }
};


int main() {
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    return 0;
}
