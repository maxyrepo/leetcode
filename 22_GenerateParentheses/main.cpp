#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <set>

using namespace std;

void output(const vector<string> & vec) {
    for(size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
    cout << endl;
}


class Solution {
public:
    set<string> res_dedup;
    void generateParenthesisRecursive(const string& cur, int cnt_l, int cnt_r) {
        if (cnt_l == 0 && cnt_r == 0) {
            res_dedup.insert(cur);
        }
        else {
            if (cnt_l == cnt_r) {
                generateParenthesisRecursive(cur + "(", cnt_l - 1, cnt_r);
            }
            else {
                if (cnt_l > 0) {
                    generateParenthesisRecursive(cur + "(", cnt_l - 1, cnt_r);
                    generateParenthesisRecursive(cur + ")", cnt_l, cnt_r - 1);
                }
                else {
                    generateParenthesisRecursive(cur + ")", cnt_l, cnt_r - 1);
                }
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        res_dedup.clear();
        vector<string> res;
        generateParenthesisRecursive("", n, n);
        for (set<string>::iterator it = res_dedup.begin(); it != res_dedup.end(); ++it) {
            res.push_back(*it);
        }
        return res;
    }
};

int main () {
    Solution s;
    output(s.generateParenthesis(1));
    output(s.generateParenthesis(3));
    output(s.generateParenthesis(4));
}
