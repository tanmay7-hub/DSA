class Solution {
public:
    vector<vector<int>> dir = { {1 , 0 } , {-1 , 0 } , {0 , 1} , {0 , -1}};
    long long dp[1001][1001];
    int mod = 1e9 + 7;
    bool isValid ( vector<vector<int>>& grid , int i , int j ){
        int n = grid.size() , m = grid[0].size();
        return (i >= 0 && i < n && j >= 0  && j < m);
    }
    long long solve( vector<vector<int>>& grid , int i , int j ){
         long long ans = 0;

         if(dp[i][j] != -1) return dp[i][j];

         for(auto vec : dir){
            int new_i = i + vec[0];
            int new_j = j + vec[1];

            if(isValid(grid , new_i , new_j)  && grid[new_i][new_j] > grid[i][j]){
                ans += (1LL + solve(grid , new_i , new_j)) % mod; 
            }
         }
         return dp[i][j] = ans % mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        long long ans = 0;
        memset(dp , -1 , sizeof(dp));
        for(int i = 0 ; i < grid.size() ; i++ ){
            for(int j = 0 ; j < grid[0].size() ; j++ ){
                ans += (1LL + solve(grid , i , j )) % mod;
            }
        }
        return ans % mod;
    }
};