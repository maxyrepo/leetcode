#include <iostream>

using namespace std;

class Solution {
public:
    long long reverse_ab(long long x) {
        long long res = 0;
        long long max_exp = 1;
        while (x > 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
    int reverse(int x) {
        long long threshold = 1;
        threshold = (threshold << 31);
        long long neg_threshold = - threshold;
               if (x > 0) {
            long long res = reverse_ab(x);
            if (res >= threshold) {
                return 0;
            }
            else {
                return res;
            }
        }
        else {
            long long res = -reverse_ab(-x);
            if (res < neg_threshold) {
                return 0;
            }
            else {
                return res;
            }
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
