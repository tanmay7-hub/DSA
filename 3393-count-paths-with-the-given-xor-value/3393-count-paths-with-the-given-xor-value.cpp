class Solution {
public:
    int n , m , k;
    int mod = 1e9 + 7;
    int dp[301][301][32];
    long long solve(int i , int j , vector<vector<int>>& grid , int x){
        if(i < 0 || i >= n || j < 0 || j >= m )return 0;
        x = x ^ grid[i][j];
        
        if(i == n - 1 && j == m - 1 ){
           return x == k  ? 1 : 0;
        }

        if(dp[i][j][x] != -1)return dp[i][j][x] % mod;

        long long right = solve(i , j + 1 , grid , x);
        long long down  = solve(i + 1 , j , grid , x);


        return dp[i][j][x] = (right + down) % mod;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        n = grid.size() , m = grid[0].size() ;
        this->k = k ;

        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , grid , 0 );
    }
};