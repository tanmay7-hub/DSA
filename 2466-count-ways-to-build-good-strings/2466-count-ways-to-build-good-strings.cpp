class Solution {
public:
    int low , high , zero , one;
    long long dp[100005];
    int mod = 1e9 + 7;
    long long solve(int len){
        if(len > high )return 0;
        
        if(dp[len] != -1)return dp[len];
        long long take_zero =  solve(len + zero) % mod ;
        long long take_one  =  solve(len + one)  % mod;

        return dp[len] = ((len <= high && len >= low ) + take_zero + take_one) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
         this-> low = low;
         this->high = high ;
         this->zero = zero;
         this->one = one;
         memset(dp , -1 , sizeof(dp));
        return solve(0);
    }
};