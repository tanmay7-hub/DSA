class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mx = nums[0];
    
        for(int i = 0 ; i <nums.size() ;i++){
            mx=max(mx,nums[i]);
            int mn = nums[i];
            for( int j = i ;j < nums.size() ;j++){
                mn=min(mn,nums[j]);
            }  
           if( mx - mn <= k){
            return i;
           }
        }
        return -1;
    }
};