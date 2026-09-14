class Solution {
public:
    int dp[21][5000 * 2 + 1];
    int solve( vector<int>& rods , int idx ,  int diff ){
          if(idx == rods.size()){
            if(diff == 0 )return 0;
            return INT_MIN;
          }
          
          if(dp[idx][diff + 5000] != -1)return dp[idx][diff + 5000];
          int a = solve(rods , idx + 1 ,diff);
          int b = solve(rods , idx + 1 , diff + rods[idx]);
          int c = rods[idx] + solve(rods , idx + 1 , diff -  rods[idx]);

          return dp[idx][diff + 5000] = max({a , b , c});     
    }
    int tallestBillboard(vector<int>& rods) {
       memset(dp , -1 , sizeof(dp));
       return solve(rods , 0 , 0  ); 
    }
};