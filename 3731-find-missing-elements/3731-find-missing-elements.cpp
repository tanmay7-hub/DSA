class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums) , end(nums));
        vector<int>ans;
        int j = 0;
        for(int i = nums[0] ; i < nums[n - 1] ; ){
            if(nums[j] == i){
                  j++;
                  i++; 
            }else{
                ans.push_back(i++);
            }
        }
        return ans;
    }
};