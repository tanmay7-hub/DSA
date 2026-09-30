class Solution {
public:
    bool solve(int sz, vector<int>& nums) {
        if (nums.size() < sz) return false;

        vector<int> fre(501, 0);
        for (int i = 0; i < sz; i++) {
            fre[nums[i]]++;
        }
        
        int l = 0 , r = sz - 1 ;
        bool valid = true;
        while( r < nums.size()){
            valid = true;
            for(int i = 0 ; i < 501 ; i++ ){
                if(fre[i] == 0 )continue;
                for(int j = i  ; j < 501 ; j++ ){
                    if(fre[j] == 0 )continue;

                    int val = i + j ;
                    if(val > 500 || fre[val] == 0 )continue;
                    if(i == j && fre[i] < 2)continue;

                    
                    valid = false;
                    break;
                }
                if(!valid)break;
            }

            if(valid) return true;

            fre[nums[l]]--;
            l++;
            r++;
            if(r < nums.size()){
                fre[nums[r]]++;
            }
            
        }
        return false;

    }
    int maxSubarray(vector<int>& nums) {
        int l = 1, r = nums.size();
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (solve(mid, nums)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};