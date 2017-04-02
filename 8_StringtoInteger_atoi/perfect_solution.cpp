#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, base = 0, i = 0;
        while (i < str.size() && str[i] == ' ') { i++; }
        if (i < str.size() && str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i++] == '-'); 
        }
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base  = 10 * base + (str[i++] - '0');
        }
        return base * sign;
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
