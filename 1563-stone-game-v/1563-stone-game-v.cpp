class Solution {
public:
    vector<int> pre;
    int dp[501][501];
    int solve( int st , int end){

        int ans = 0;
        if(dp[st][end] != -1)return dp[st][end];
        for(int i = st ; i <= end ; i++ ){
           int left = pre[i] - (st - 1 >= 0 ? pre[st - 1] : 0);
           int right = pre[end ] - pre[i];
           
           if(left < right){
             ans = max(ans ,left + solve(st , i));
           }
           else if(right < left){
            ans = max(ans , right + solve(i + 1, end));
           }else{
             ans = max({ans ,left + solve(st , i) , right + solve(i + 1 , end)});
           }
        }
        return dp[st][end] =  ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();     
        memset(dp , -1 , sizeof(dp) );
        pre.resize(n);
        pre[0] = stoneValue[0];
        for(int i = 1 ; i < n ; i++){
            pre[i] = pre[i - 1] + stoneValue[i];
        }
        return solve( 0 , n  - 1);
    }
};