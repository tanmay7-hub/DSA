class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n = nums.size();

       int curr = 0;
       int i = 0;
       for( i ; i < nums.size() ; i++ ){
         if( i + nums[i] > curr && curr >= i )curr = i + nums[i];
       }
       return curr >= n - 1;
    }
};