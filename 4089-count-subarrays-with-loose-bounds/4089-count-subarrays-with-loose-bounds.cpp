class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int i = 0 , j = 0;
        long long ans = 0;

        while(j  < nums.size() ){
           
           if(nums[j] <= maxK && nums[j] >= minK){
             ans += j - i + 1;
             
           }else{
              i = j + 1;
              
           }
           j++;
        }

        return ans;
    }
};