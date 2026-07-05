class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int>dig(10 , 0 );
        int ansIdx = -1;
        for(int num : nums) {
            int curr = num ;
            int mn = INT_MAX, mx = INT_MIN ;
            while(curr){
               mn = min(mn , curr % 10 );
               mx = max(mx , curr % 10 );

               curr /= 10;
            }
            ansIdx = max(ansIdx , mx - mn );
            dig [mx - mn] += num;

        }
        return dig[ansIdx];

    }
};