class Solution {
public:
    int n, m;
    const int MOD = 1e9 + 7;
    
    int dp[501][501][3];
    int solve(int i, int j , int ch, vector<vector<int>>& grid) {
        if (i == n - 1 && j == m - 1)
            return 1;

        if (i >= n || j >= m)
            return 0;

        if (dp[i][j][ch] != -1)
            return dp[i][j][ch];

        long long ans = 0;

        if(grid[i][j] == 1){
            ans = ans +  (ch == 0 ? solve(i + 1, j  , 1 , grid) : solve(i  , j + 1 , 0 , grid));
            
            return dp[i][j][ch] = ans % MOD;
        }

        ans += solve(i + 1 , j , 1 , grid);
        ans += solve(i , j + 1 , 0 , grid);

        

        return dp[i][j][ch] = ans % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , 2 ,  grid);
    }
};