class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int> , int> mp;
        int cnt = 0;
        for(int i = 1 ; i < nums.size() ; i++ ){
            int a = nums[i - 1];
            int b = nums[i];
            
            if(a == b ){
                cnt++;
            }else{
                mp[{a , b}]++;
                mp[{b , a}]++;
            }  
        } 
         int ans = 0;
        for(auto &[p , fre] : mp){
            ans  = max(ans , fre);
        }
        return ans + cnt;
    }
};