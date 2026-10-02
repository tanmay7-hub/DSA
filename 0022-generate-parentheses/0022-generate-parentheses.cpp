class Solution {
public:
    void solve(vector<string>& ans, string s, int open, int close, int n) {
        if (open == close && close == n) {
            ans.push_back(s);
            return;
        }
        if (open > n || close > n)
            return;
        if (open == close) {
            s += '(';
            solve(ans, s, open + 1, close, n);
        } else {
            s += '(';
            solve(ans, s, open + 1, close, n);
            s.pop_back();
            s += ')';
            solve(ans, s, open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(ans, s, 0, 0, n);
        return ans;
    }
};