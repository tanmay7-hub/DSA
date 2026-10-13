class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++ ){
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int sz = ( nums.size() + 1 ) / 2;

        
       long long ans = 0;
        for(int i = 0 ; i < n ; i++ ){
            
            if(i < n - sz){
                ans -= nums[i] * 1LL * nums[i];
            }else{
                ans += nums[i] * 1LL * nums[i];
            }
        }
        return ans;
    }
};