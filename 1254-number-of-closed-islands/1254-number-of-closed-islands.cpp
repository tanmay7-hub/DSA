class Solution {
public:
    bool solve(vector<vector<int>>& grid , int i , int j ){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return false;
        }

        if(grid[i][j]  )return true;
        grid[i][j] = 1;
        return solve(grid , i + 1 , j ) & solve(grid , i , j + 1 ) & solve(grid , i , j - 1 ) & solve(grid , i - 1 , j);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i = 0 ; i < grid.size() ; i++ ){
            for(int j = 0 ; j < grid[0].size() ; j++ ){
                if(!grid[i][j]) ans += solve(grid , i , j );
            }
        }

        return ans;
    }
};