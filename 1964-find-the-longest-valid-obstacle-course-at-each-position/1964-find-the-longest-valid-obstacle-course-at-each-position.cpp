class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        vector<int> lis;
        for(int i = 0 ; i < n ; i++ ){
            auto it = upper_bound(lis.begin() , lis.end() , nums[i]);
            int pos = it - lis.begin();
            if(it == lis.end()){
                lis.push_back(nums[i]);
            }else{
                *it = nums[i];
            }

            dp.push_back(pos + 1 );
        }

        return dp;
    }
};