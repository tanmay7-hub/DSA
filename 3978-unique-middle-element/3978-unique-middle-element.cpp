class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = ( n - 1) / 2;
        int count = 0;
        for(int num : nums)if(num == nums[mid]) count++;

        return count == 1;
    }
};