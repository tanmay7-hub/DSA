class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> fre(n + 1 , 0);
        for(int i = 0 ; i < nums.size() ; i++ ){
            fre[nums[i]]++;
        }

        int missing = -1 , duplicate = -1;
        for(int i = 1 ; i <= n ; i++ ){
            if(fre[i ] == 0){
                missing = i ; 
            }else if(fre[i] == 2){
                duplicate = i;
            }
        }
        return { duplicate , missing};
    }
};