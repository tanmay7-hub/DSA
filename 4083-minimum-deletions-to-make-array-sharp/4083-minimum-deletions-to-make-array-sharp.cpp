class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int i = 0 , j = 1;
        int count = 0;
        while(  j < nums.size()){
             
            if((nums[i] ^ nums[j]) == 0){
                j++;
                count++;
            }else{
                i = j;
                j++;
            }
        }
        return count;
    }
};