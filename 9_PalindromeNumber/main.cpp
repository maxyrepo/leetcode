#include <iostream>

using namespace std;

class Solution {
public:
    int get_digit_at_pos(int x, int p) {
        int exp = 1;
        for (int i = 0; i < p - 1; ++i) {
            exp *= 10;
        }
        x /= exp;
        if (x >= 10) {
            x %= 10;
        }
        return x;
    }

    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
    
        int len = 1;
        int tmp = x;
        while (tmp >= 10) {
            ++len;
            tmp /= 10;
        }
    
        int l = len;
        int r = 1;
        while (l > r) {
            int digit_l = get_digit_at_pos(x, l);
            int digit_r = get_digit_at_pos(x, r);
            if (digit_l != digit_r) {
                return false;
            }
            r++;
            l--;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(9) << endl;
    cout << s.isPalindrome(11) << endl;
    cout << s.isPalindrome(1001) << endl;
    cout << s.isPalindrome(123) << endl;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(12345321) << endl;
}
