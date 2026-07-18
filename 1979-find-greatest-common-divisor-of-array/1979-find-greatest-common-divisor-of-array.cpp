class Solution {
public:
    int findGCD(vector<int>& nums) {
         int sm=*min_element(nums.begin(),nums.end());
         int mx=*max_element(nums.begin(),nums.end());
         return __gcd(sm,mx);
    }
};