class Solution {
public:
    int n , m ;
    vector<vector<int>> dir = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};
    bool isValid(int i , int j ){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int dp[201][201];
    int solve(int i , int j , vector<vector<int>>& mat){
        int ans = 1;

        if(dp[i][j] != - 1)return dp[i][j];
        for(auto &vec : dir) {
            int new_i = i + vec[0];
            int new_j = j + vec[1];

            if(isValid(new_i , new_j) && mat[new_i][new_j]  > mat[i][j]){
                ans = max(1 + solve(new_i , new_j , mat) ,  ans);
            } 
        }
        return dp[i][j] = ans;      
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp , -1 , sizeof(dp));
        n = matrix.size() , m = matrix[0].size();
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++){           
                  ans = max(ans , solve(i , j , matrix));
            }
        }
        return ans;
    }
};