class Solution {
public:
   int dp[501][501];
    int solve(string &s , int st , int end){
        if(st >= end) return 0; 
        int ans = INT_MAX;
         
        if(dp[st][end] != -1) return dp[st][end];
        if(s[st] == s[end]){
            ans =  solve(s , st + 1 , end - 1 );
        }else{
            ans = 1 +  min(solve(s , st + 1 , end ) , solve( s , st , end - 1 ));
        }
        return dp[st][end] = ans;
    }
    int minInsertions(string s) {
        memset(dp , -1 , sizeof(dp));
        int n = s.size();
        return solve(s , 0 , n - 1);
    }
};