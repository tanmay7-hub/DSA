class Solution {
public:
    int solve(int i ){
        int sum = 0 ;
        while(i){
            sum += i % 10;
            i/= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++ ){
            int sum = solve(nums[i]);

            if(i ==  sum ){
                return i ;
            }
        }

        return -1;
    }
};