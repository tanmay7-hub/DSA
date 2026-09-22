class Solution {
public:
    unordered_set<string> mp;
    int dp[51];
    int solve(string& s, int index) {
        if (index >= s.size())
            return 0;
        
        if(dp[index] != -1)return dp[index];
        string currStr = "";
        int minExtra = s.size();
        for (int cutIdx = index; cutIdx < s.size(); cutIdx++) {
            currStr.push_back(s[cutIdx]);

            int currExtra = (mp.count(currStr)) ? 0 : currStr.size();
            int nextExtra = solve(s,  cutIdx + 1);
            int totalExtra = currExtra + nextExtra;

            minExtra = min(minExtra, totalExtra);
        }
        return dp[index] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp , -1 , sizeof(dp));
        for (auto str : dictionary) {
            mp.insert(str);
        }

        return solve(s, 0);
    }
};