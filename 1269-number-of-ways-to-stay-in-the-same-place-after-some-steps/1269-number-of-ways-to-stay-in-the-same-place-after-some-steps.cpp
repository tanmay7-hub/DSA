class Solution {
public: 
    int arrLen;
    int mod = 1e9 + 7;
    int dp[501][501];
    long long solve(int i , int step){
        if(step == 0){
            return i == 0;
        }
        long long ans = 0;

        if(dp[i][step] != -1) return dp[i][step];
        ans += solve(i , step - 1) % mod;
        if(i - 1  >= 0){
         ans += solve(i - 1 , step - 1) % mod;
        }
        if(i + 1 < arrLen){
         ans += solve(i + 1 , step - 1) % mod;
        }


       return  dp[i][step] = ans % mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp , -1 ,sizeof(dp));
        this->arrLen = arrLen;
        return solve(0 , steps ) ;
    }
};