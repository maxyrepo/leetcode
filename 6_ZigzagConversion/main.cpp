#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        int run = (s.size() - 1) / (2*numRows - 2) + 1;
        int cur_idx = 0;
        string result(s.size(), '\0');
    
        //first line
        for(int r = 0; r < run; ++r) {
            if ((2*numRows - 2)*r < s.size()) {
                result[cur_idx++] = s[(2*numRows - 2)*r];
            }
        }
        //2nd, ..., numRows - 1 lines;
        for (int l = 1; l < numRows - 1; ++l) {
            for (int r = 0; r < run; ++r) {
                if (l + (2*numRows -2 ) * r < s.size()) {
                    result[cur_idx++] = s[l + (2*numRows -2 ) * r];
                }
                if (-l + (2*numRows -2 ) * (r + 1) < s.size()) {
                    result[cur_idx++] = s[-l + (2*numRows -2 ) * (r + 1)];
                }
            }
        }
        //last line
        for(int r = 0; r < run; ++r) {
            if (numRows - 1 + (2*numRows - 2)*r < s.size()) {
                result[cur_idx++] = s[numRows - 1 + (2*numRows - 2)*r];
            }
        }
    
        return result;
    }
};

int main() {
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}
