
class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, m;
    int dp[501][501][3];

    int solve(int i, int j, int dir,
              vector<vector<int>>& grid) {

        if (i >= n || j >= m)
            return 0;

        if (i == n - 1 && j == m - 1)
            return 1;

        int &res = dp[i][j][dir];

        if (res != -1)
            return res;

        long long ans = 0;

        if (grid[i][j] == 1) {

            if (dir == 0) {

                ans = solve(i + 1, j, 1, grid);
            }
            else if (dir == 1) {

                ans = solve(i, j + 1, 0, grid);
            }

        } 
        else {


            ans += solve(i, j + 1, 0, grid);

            ans += solve(i + 1, j, 1, grid);
        }

        return res = ans % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 2, grid);
    }
};
