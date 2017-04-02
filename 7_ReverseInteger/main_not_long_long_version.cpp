#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse_ab(int x, bool if_neg) {
        int res = 0;
        while (x > 0 && res < INT_MAX/10) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (x > 0) {
            if (res > INT_MAX/10) {
                res = 0;
            }
            else if (res == INT_MAX/10) {
                if (!if_neg) {
                    if (x <= 7) {
                        res = res * 10 + x;
                    }
                    else {
                        res = 0;
                    }
                }
                else {
                    if (x <= 8) {
                        res = res * 10 + x;
                    }
                    else {
                        res = 0;
                    }
                }
            }
        }
        return res;
    }
    int reverse(int x) {
        if (x > 0) {
            return reverse_ab(x, false);
        }
        else {
            return -reverse_ab(-x, true);
        }
    }
};

int main () {
    Solution s;
    cout << s.reverse(123) << endl;
    cout << s.reverse(-123) << endl;
    cout << s.reverse(2147483647) << endl;
    cout << s.reverse(-2147483647) << endl;
    cout << s.reverse(2147483648) << endl;
    cout << s.reverse(-2147483648) << endl;
    cout << s.reverse(21474836480) << endl;
    cout << s.reverse(-21474836480) << endl;
}
