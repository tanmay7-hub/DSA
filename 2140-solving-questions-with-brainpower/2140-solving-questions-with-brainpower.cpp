class Solution {
public:
    long long dp[100005];
    long long solve(vector<vector<int>>& nums , int idx){
         if(idx >= nums.size()) return 0;

         if(dp[idx] != -1)return dp[idx];
         long long take = nums[idx][0] + solve(nums , idx + nums[idx][1] + 1);
         long long not_take = solve(nums , idx + 1 );


         return dp[idx] = max(take , not_take);
    }
    long long mostPoints(vector<vector<int>>& nums) {
         int n = nums.size();
         memset(dp , -1 , sizeof(dp));
        return solve(nums , 0 );
    }
};