#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        else if (strs.size() == 1) {
            return strs[0];
        }
    
        string prefix = "";
        size_t idx = 0;
        bool stop_flag = false;
        while (!stop_flag) {
            for(size_t i = 0; i < strs.size() - 1; ++i) {
                if (strs[i].size() <= idx || strs[i+1].size() <= idx || strs[i][idx] != strs[i+1][idx]) {
                    stop_flag = true;
                    break;
                }
            }
            if (!stop_flag) {
                prefix += string(1, strs[0][idx]);
                idx++;
            }
        }
    
        return prefix;
    }
};

int main() {
    vector<string> vec;
    vec.push_back("abc");
    vec.push_back("ab");
    vec.push_back("a");

    Solution s;
    cout << s.longestCommonPrefix(vec) << endl;
}
