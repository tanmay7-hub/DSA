class Solution {
public:
    int n , m ;
    void shift(vector<vector<int>>& grid){
        int prev = grid[n - 1][m - 1];
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++ ){      
                  swap(prev , grid[i][j]);
            }
        }

    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        n = grid.size() ; 
        m = grid[0].size();
        int sz = n * m;
        k = k % sz;

        for(int i = 1 ; i <= k ;i++ ){
            shift(grid);
        }
        return grid;
    }
};