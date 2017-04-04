class Solution {
public:
    void combs(int n, int sum, string& s, vector<string> &res) {
        if (s.size() >= 2*n) { res.push_back(s); }
        else {
            if (s.size() - sum < n) {
                s = s + "("; combs(n, sum, s, res); s.resize(s.size() - 1);
            }
            if (s.size() - sum > sum) {
                s = s + ")"; combs(n, sum+1, s, res);  s.resize(s.size() - 1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "(";
        combs(n, 0, s, res);
        return res;
    }
};
