class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long ans = 0;

        for(auto num : nums)ans ^= num;

        long long mask = ans & (-ans);
        int first = 0;
        int second = 0;
        for(auto num : nums){
            if(num & mask){
                first ^=num;
            }else{
                second ^=num;
            }
        }
        return {first , second};
    }
};