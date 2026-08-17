class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(begin(nums) , end(nums));
        int n = nums.size();
        int i = 0 , j = n - 1;
        long long ans = 0;
        while(i < j){
            ans += nums[j - 1];
            i++;
            j -= 2;
        } 
        return ans;
    }
};