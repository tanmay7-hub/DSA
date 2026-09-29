class Solution {
public:
    int dp[101][101][202];
    int n , m;
    vector<vector<char>> grid;
    vector<vector<int>> dir = {{1 , 0} , {0 , 1}};
    bool isValid(int i , int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    bool solve(int i , int j , int curr ){
        if(curr > 0) return false;
        curr += (grid[i][j] == '(' ? -1 : 1);
        if(i == n - 1 && j == m - 1){
            return dp[i][j][curr + 200] = ( curr == 0 );
        } 
        
        if(dp[i][j][curr + 200] != -1 ) return dp[i][j][curr + 200];
        for(auto v : dir ){
            int new_x = v[0] + i ;
            int new_y = v[1] + j ;

            if(isValid(new_x, new_y)) {

                bool next = solve(new_x , new_y , curr );
                if(next) return dp[i][j][curr + 200] = true;
            }
        }

        return dp[i][j][curr + 200] = false;

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp , -1 , sizeof(dp));
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        return solve(0 , 0  , 0);
    }
};