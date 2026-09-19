class Solution {
public:
    vector<vector<int>> moves ={{4 , 6} , {8 , 6} , {7 , 9} , {4 , 8} , {0 , 3 ,9} ,{} , {1 , 7 , 0} , {2 , 6} , {1 , 3} , {2 , 4}};
    int dp[10][5001];
    int mod = 1e9 + 7;
    int solve(int curr, int n) {
        if (n == 0) {
            return 1;
        }

        if(dp[curr][n] != - 1)return dp[curr][n];
        long long ans = 0;
        for(auto it : moves[curr]){
            ans += solve(it , n - 1) ;
            ans %= mod;
        }
        
        return dp[curr][n] = ans % mod;

    }
    int knightDialer(int n) {
        long long ans = 0;
        memset(dp , -1 , sizeof(dp));
        for (int i = 0 ; i <= 9; i++) {
            ans = ( ans + solve(i, n - 1)) % mod;
        }

        return ans % mod;
    }
};