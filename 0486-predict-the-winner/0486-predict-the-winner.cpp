class Solution {
public:
    bool solve(int i , int j , int one , int two ,int turn ,  vector<int> & nums){
         if(j < i )return  one >= two;
         if(turn){         
              return solve(i + 1 , j , one + nums[i] , two  , !turn , nums) || 
                     solve(i , j - 1 , one + nums[j] , two  , !turn , nums)  ;
         }else{         
             return solve(i + 1 , j  , one  , two  + nums[i], !turn , nums) && 
                     solve(i , j - 1 , one , two + nums[j] , !turn , nums);
         }
    }
    bool predictTheWinner(vector<int>& nums) {
       int n = nums.size();
        if(n == 0 || n == 1)return true;      
        return solve(0 , n - 1 , 0 , 0 , 1 , nums);
    }
};