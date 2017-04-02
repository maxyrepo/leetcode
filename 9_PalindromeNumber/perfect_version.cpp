//An easy c++ 8 lines code (only reversing till half and then compare)

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
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
