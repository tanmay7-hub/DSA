class Solution {
public:
    vector<vector<int>> dir = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                               {2, -1}, {1, -2}, {-1, -2}, { -2 , -1}};
    
    bool isValid(int row , int col , int n){
        return (row >= 0 && row < n && col >= 0 && col < n);
    }
    double dp[26][26][101];
    double solve(int n, int k, int row, int col) {
        if (k == 0 ){       
           return 1.0 ;
        }

        if(dp[row][col][k] != -1) return dp[row][col][k];
        double ans = 0;
            for (auto vec : dir) {
                int new_row = vec[0] + row;
                int new_col = vec[1] + col;
                    
               if(isValid(new_row , new_col , n)) ans +=  solve(n, k - 1, new_row, new_col) / 8.0;
            }

        return dp[row][col][k] = ans ;  
    }
    double knightProbability(int n, int k, int row, int column) {
        // memset(dp , -1.0 , sizeof(dp));
        fill(&dp[0][0][0] , &dp[0][0][0] + 26 * 26 * 101 , -1.0);
        double count = solve(n, k, row, column);
        return count ;
    }
};