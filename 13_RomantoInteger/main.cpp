#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> alphabet;
        alphabet['I'] = 1;
        alphabet['V'] = 5;
        alphabet['X'] = 10;
        alphabet['L'] = 50;
        alphabet['C'] = 100;
        alphabet['D'] = 500;
        alphabet['M'] = 1000;
    
        int res = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (i < s.size() - 1 && alphabet[s[i]] < alphabet[s[i+1]]) {
                res -= alphabet[s[i]];
            }
            else {
                res += alphabet[s[i]];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("I") << endl;
    cout << s.romanToInt("X") << endl;
    cout << s.romanToInt("CCLXXXIX") << endl;
    cout << s.romanToInt("MMMCMXCIX") << endl;
}
