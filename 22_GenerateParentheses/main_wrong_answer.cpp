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
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return vector<string>(0);
        }
        else if (n == 1) {
            return vector<string>(1, "()");
        }
        else {
            vector<string> res;
            vector<string> sub_result = generateParenthesis(n-1);
            set<string> res_dedup;
            for(size_t i = 0; i < sub_result.size(); ++i) {
                res_dedup.insert("()" + sub_result[i]);
                res_dedup.insert(sub_result[i] + "()");
                res_dedup.insert(string("(") + sub_result[i] + string(")"));
            }
            for(set<string>::iterator it = res_dedup.begin(); it != res_dedup.end(); ++it) {
                res.push_back(*it);
            }
            return res;
        }
    }
};

int main () {
    Solution s;
    output(s.generateParenthesis(3));
}
