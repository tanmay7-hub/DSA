class Solution {
public:
    int MOD = 1e9 + 7;
    unordered_map<int , int > dp;
    long long solve(string &s , int k , int idx){
      if(idx == s.size()){
         return 1;
      }

      int key = idx;
      if(dp.find(key) != dp.end()) return dp[key];

      long long curr_num = 0 ;
      long long ways = 0;
      for(int i = idx ; i < s.size() ; i++ ){
            int currDig = s[i] - '0';
            curr_num = (10 * curr_num) + currDig ;

            if(curr_num < 1 || curr_num > k )break;
            
            int next_ways = solve(s , k , i + 1);

            ways += next_ways;
      }    
       return dp[key] = (ways) % MOD;  
    } 
    int numberOfArrays(string s, int k) {
        return solve(s , k  , 0 ) % MOD;
    }
};