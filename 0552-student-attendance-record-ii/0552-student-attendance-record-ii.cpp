class Solution {
public:
    int mod = 1e9+7;
    long long dp[100001][3][3];
    long long solve(int n, int l, int a) {
        if (n == 0)
            return 1;
        if (a >= 2 )
            return 0;

        if(dp[n][l][a] != -1)return dp[n][l][a];
        long long ans = 0;
        //    present
        ans += solve(n - 1, 0, a) % mod;
        //    late
        if (l < 2) {
            ans += solve(n - 1, l + 1, a) % mod;
        }
        //    absent
        if (a < 1) {
            ans += solve(n - 1, 0, a + 1) % mod;
        }

        return dp[n][l][a] = ans % mod;
    }
    int checkRecord(int n) {
         memset(dp , -1 ,sizeof(dp));
         return solve(n, 0, 0) % mod;
    }
};