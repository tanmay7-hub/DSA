class Solution {
public:
    int dp[1001][2001];
    int solve( vector<vector<int>>& piles , int idx , int k ){
        if (idx >= piles.size() || k == 0) return 0;
        if(dp[idx][k] != -1)return dp[idx][k];
        int not_take = solve(piles , idx + 1 , k ); 
        int take = 0 ;
        for(int i = 0 ; i < piles[idx].size() && i < k; i++ ){
          take = max(take , piles[idx][i] + solve(piles , idx + 1 , k - (i + 1)));
           
        }
        return dp[idx][k] = max(take , not_take);
    }
    int maxValueOfCoins(vector<vector<int>> & piles, int k) {
        
        memset(dp, -1 , sizeof(dp));
        for(int i = 0 ; i < piles.size() ; i++ ){
            int curr = 0 ;
            for(int j = 0 ; j < piles[i].size() ; j++ ){
                curr += piles[i][j];
                piles[i][j] = curr;
            }
        }
        return solve(piles , 0 , k );
    }
};