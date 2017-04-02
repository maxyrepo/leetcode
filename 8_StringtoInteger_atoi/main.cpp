#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
            if (str.size() == 0) {
            return res;
        }
    
        int idx = 0;
        while(str[idx] == ' ') {
            ++idx;
        }
    
        bool if_neg = false;
        if (str[idx] == '-') {
            if_neg = true;
            ++idx;
        }
        else if (str[idx] == '+') {
            if_neg = false;
            ++idx;
        }
    
        for(; idx < str.size(); ++idx) {
            int x = str[idx] - '0';
            if (x > 9 || x < 0) {
                break;
            }
            if (res < INT_MAX / 10) {
                res = res * 10 + x;
            }
            else if (res == INT_MAX / 10) {
                if (if_neg) {
                    if (x < 8) {
                        res = res * 10 + x;
                    }
                    else {
                        return INT_MIN;
                    }
                }
                else if (!if_neg) {
                    if (x <= 7) {
                        res = res * 10 + x;
                    }
                    else {
                        return INT_MAX;
                    }
                }
            }
            else {
                if (if_neg) {
                    return INT_MIN;
                }
                else {
                    return INT_MAX;
                }
            }
        }
        return if_neg ? -res : res;
    }
};

int main(int argc, char ** argv) {
    if (argc != 2) {
        cerr << "invalid parameter" << endl;
        return -1;
    }
    Solution s;
    cout << s.myAtoi(argv[1]) << endl;
    return 0;
}
