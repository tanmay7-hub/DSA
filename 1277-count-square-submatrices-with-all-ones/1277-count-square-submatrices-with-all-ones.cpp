class Solution {
public:
    int countSquares(vector<vector<int>>& dp) {
        int n = dp.size(), m = dp[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++ )ans += dp[i][0];
        for(int i = 1 ; i < m ; i++ )ans += dp[0][i];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {

                if (dp[i][j] == 1) {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    ans += dp[i][j];
                }
            }
        }

        return ans;
    }
};