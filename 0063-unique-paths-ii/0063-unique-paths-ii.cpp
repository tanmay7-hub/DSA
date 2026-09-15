class Solution {
public:
    vector<vector<int>> dir = {{1, 0} , {0, 1}};
    int n , m;
    int dp[101][101];
    bool isValid(int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    int solve(vector<vector<int>>& grid, int row, int col) {
        if(grid[row][col] == 1)return 0;
        if (row == n - 1 && col == m - 1)
            return 1;
        int ans = 0;

        if(dp[row][col] != -1)return dp[row][col];
        for(auto &vec : dir) {
            int new_row = row + vec[0];
            int new_col = col + vec[1];

            if (isValid(new_row, new_col) && grid[new_row][new_col] == 0 ) {
                ans += solve(grid, new_row, new_col);
            }
        }
        return dp[row][col] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp , -1 , sizeof(dp));
        n = obstacleGrid.size(), m = obstacleGrid[0].size();
        return solve(obstacleGrid, 0, 0);
    }
};