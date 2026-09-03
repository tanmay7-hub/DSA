class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int odd = 0 , even = 0;
        for(int i = 0 ; i < n ; i++ ){
               ( nums1[i] % 2 == 0 ) ? even++ : odd++;
        }
        if( odd == 0 || even == 0 )return true;

        int mn = INT_MAX;
        for(int num : nums1){
            if( num % 2 == 1 ) mn = min(mn,num);
        }

        for(int num : nums1){
            if( num % 2 == 0 && num - mn < 1 )return false;
        }
        return true;
    }
};