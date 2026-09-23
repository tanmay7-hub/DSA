class Solution {
public:
    int dp[1001][1001];
    int mod = 1e9 + 7;
    int solve(int n , int k ){
        if(n == 0 ) return 0;
        if(k == 0 ) return 1;

        long long ans = 0 ;
        if(dp[n][k] != -1)return dp[n][k];
        for(int i = 0 ; i <= min(n - 1 , k) ; i++ ){
            ans = ans + solve(n - 1 , k - i ) % mod;
            ans %= mod;
        }
        return dp[n][k] = ans % mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp , -1 , sizeof(dp));
        return solve(n , k );
    }
};