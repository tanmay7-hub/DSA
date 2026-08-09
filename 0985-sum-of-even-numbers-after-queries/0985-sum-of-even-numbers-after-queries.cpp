class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;

        for(auto num : nums) if(num % 2 == 0) ans += num;

        vector<int> res;
        for(auto q : queries){
            int idx = q[1] , val = q[0];
            
            if(val % 2 == 0 && nums[idx] % 2 ==0){
                nums[idx] += val;
                ans += val;
            }else if(!(val % 2 == 0) && !(nums[idx] % 2 == 0)){
                nums[idx] += val;
                ans += nums[idx];
            }else{
                if(nums[idx] % 2 == 0) ans -= nums[idx];
                nums[idx] += val;
            }
            res.push_back(ans);
        }
        return res;
    }
};