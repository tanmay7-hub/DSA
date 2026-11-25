class Solution {
public:
    typedef unsigned long long ull;
    ull getHash(vector<ull>&power, vector<ull>&pf , int l , int r , int mid){
        return pf[r + 1] - pf[l] * power[mid];
    }
    bool possible( vector<ull>&power, vector<ull>&pf , int mid , int n){
        unordered_map<ull,int>mp;
        for(int i = 0 ; i + mid - 1 < n  ;i++){
            ull h = getHash(power , pf , i , i + mid - 1 , mid);
            mp[h]++;
        }
        for(auto p : mp){
              if(p.second == 1)return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const ull BASE = 911382323;
        vector<ull>power( n + 1 ,1);
        vector<ull>pf( n + 1 , 0);

        for(int i = 0 ; i < n ; i++ ){
              power[i + 1] = power[i] * BASE;
              pf[ i + 1 ]  = pf[i] * BASE + nums[i]; 
        }

        int start = 1 , end = n ;
        int ans = n;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(possible(power , pf , mid , n)){
                ans = mid;
                end = mid  ;
            }else{
                start = mid + 1;
            }
        }
        return ans;
       
    }
};