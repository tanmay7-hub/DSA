class Solution {
public:
    int dp[50001][2];
    int solve(vector<int>& prices, int fee, int idx, int buy) {
        if (idx >= prices.size())
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        if (buy) {

            return dp[idx][buy] =
                       max(-prices[idx] + solve(prices, fee, idx + 1, !buy),
                           solve(prices, fee, idx + 1, buy));
        }

        return dp[idx][buy] =
                   max(prices[idx] - fee + solve(prices, fee, idx + 1, !buy),
                       solve(prices, fee, idx + 1, buy));
    }
    int maxProfit(vector<int>& prices, int fee) {
        //  dp.assign(prices.size(), vector<int>(2, -1));
        memset(dp , -1 , sizeof(dp));
        return solve(prices, fee, 0, 1);
    }
};