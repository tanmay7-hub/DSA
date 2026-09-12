class Solution {
public:
    int dp[16385];
    int solve(vector<int>& nums ,int op , int  mask){
        int ans = 0;

        if(dp[mask] != -1)return dp[mask];
        for(int i = 0 ; i < nums.size() ; i++ ){
            if(mask & ( 1<< i)) continue;
            for(int j = i + 1 ; j < nums.size() ; j++ ){
                if(mask & (1 << j))continue;

                int new_mask =  mask | (1 << i) | (1 << j);
                ans =  max( ans , op * gcd(nums[i] , nums[j]) + solve(nums , op + 1 , new_mask));
                
            }
        }

        return dp[mask] = ans;
    }
    int maxScore(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        return solve(nums , 1 ,  0 );
    }
};