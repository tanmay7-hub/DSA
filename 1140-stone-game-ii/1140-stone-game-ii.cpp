class Solution {
public:
    vector<int> suffix;
    int n;
    vector<vector<int>>dp;
    int solve( int i , int m){
        if(i >= n ) return 0;


        if(dp[i][m] != -1) return dp[i][m];
       int rem = suffix[i];
       int ans = 0;
       for(int x = 1 ; x <= 2 * m  && i + x <= n ; x++ ){
          
          int opp = solve(i + x , max(m ,x));

          int curr = rem - opp;

          ans = max(curr , ans);
       }  
       return dp[i][m] = ans; 

    }
    int stoneGameII(vector<int>& piles) {
         n = piles.size();
         dp.assign(n , vector<int>(n + 1 , -1));
         suffix.resize(n , 0);
         suffix[n - 1] = piles[n - 1];

         for(int i = n - 2 ; i >= 0 ; i-- ){
            suffix[i] = suffix[i + 1] + piles[i];
         }
        return solve( 0 , 1);
    }
};