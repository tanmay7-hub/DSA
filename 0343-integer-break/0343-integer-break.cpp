class Solution {
public:
    int dp[60];
    int solve(int n) {
        if(n <= 4) return n;
        int ans = 1;

        if(dp[n] != -1)return dp[n];
        for(int i = 1 ; i <= n ; i++ ){
            ans = max(ans  , i * solve(n - i));
        } 

        return dp[n] = ans;
    }
    int integerBreak(int n) {
        memset(dp , -1 , sizeof(dp));
        if(n == 2 || n == 3) return n - 1;
        if(n == 4)return 4;
        return solve(n); 
    }
};