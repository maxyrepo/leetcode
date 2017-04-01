#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> char_idx(256, -1);
        int cur_max_len = 0;
        int global_max_len = 0;
        for(size_t i = 0; i < s.size(); ++i) {
            int pos_diff = i - char_idx[s[i]];
            cur_max_len = pos_diff < cur_max_len + 1 ? pos_diff : cur_max_len + 1;
            if (cur_max_len > global_max_len) {
                global_max_len = cur_max_len;
            }
            char_idx[s[i]] = i;
        }
        return global_max_len;
    }
};

int main() {
    Solution s;
    cout << "abcabcbb: " << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "bbbbb: " << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << "pwwkew: " << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << "a: " << s.lengthOfLongestSubstring("a") << endl;
    cout << ": " << s.lengthOfLongestSubstring("") << endl;
}
