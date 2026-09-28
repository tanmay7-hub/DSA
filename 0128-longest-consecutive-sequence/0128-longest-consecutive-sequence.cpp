class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = nums.size() > 0 ;
        int res = 0;
        for(int i = 1 ; i < nums.size() ; i++ ){
              if(nums[i] - nums[i - 1] == 1){
                ans++;
                res = max(ans , res);
              }
              else if(nums[i] == nums[i - 1]){
                continue;
              }
              else{
                ans = 1;
              }
        }
        res = max(res , ans);
        return res;
    }
};