class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l = 0;
        int sum = accumulate(begin(nums) , end(nums) , 0);

        for(int i = 0 ; i < nums.size() ; i++ ){
            if(sum - l - nums[i] == l )return i;
            l += nums[i];
        }
        return -1;
    }
};