class Solution {
public:
    int m , n ;
    vector<vector<int>> dir = {{1 , 0} , {-1 , 0 } ,{0 , 1} , {0 , -1}};
    bool isValid(int i , int j ){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int dp[51][51][51];
    int mod = 1e9 + 7; 
    int solve(int i , int j , int k ){
       if(!isValid(i , j ))return 1;
       if(k == 0 )return 0;
       long long ans = 0;

       if(dp[i][j][k] != -1)return dp[i][j][k];
       for(auto vec : dir){
        int new_r = i + vec[0];
        int new_c = j + vec[1];

        ans += solve(new_r , new_c , k - 1) ;
        ans %= mod;
        
       }
       return dp[i][j][k] = ans % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp , -1 ,sizeof(dp));
        this->m = m;
        this->n = n;

        return solve(startRow , startColumn , maxMove );
    }
};