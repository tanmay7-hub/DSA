class Solution {
public:
    const int mod = 1e9 + 7;
    int numTilings(int n) {
        vector<int>dp(n + 4);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for( int i = 4 ; i <= n ; i++ ){    
            long long curr = 2 * 1LL * dp[i - 1] + dp[ i - 3];
            curr %= mod;
            dp[i] = curr; 

        }
        return dp[n];
    }
};