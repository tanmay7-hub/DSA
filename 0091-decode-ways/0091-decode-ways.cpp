class Solution {
public:
    unordered_map<string, char> mp;
    int dp[101];
    int solve(int idx, string s) {
        if (idx >= s.size())
            return 1;
        int ans = 0;

        if(dp[idx] != -1)return dp[idx];
        string s1 = s.substr(idx, 1);
        if (mp.find(s1) != mp.end())
            ans += solve(idx + 1, s);

        if (idx + 1 < s.size()) {
            s1 = s.substr(idx, 2);
            if (mp.find(s1) != mp.end())
                ans += solve(idx + 2, s);
        }

        return dp[idx] = ans;
    }
    int numDecodings(string s) {
        memset(dp , -1 ,sizeof(dp));
        for (int i = 1; i <= 26; i++) {
            string key = to_string(i);
            char val = i - 1 + 'A';
            mp[key] = val;
        }

        return solve(0, s);
    }
};