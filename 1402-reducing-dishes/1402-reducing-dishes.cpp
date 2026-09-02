class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& vec , int idx , int time ){
        if(idx >= vec.size() ) return 0;

        if(dp[idx][time] != -1)return dp[idx][time];

        int take  = time * vec[idx] + solve(vec , idx + 1 , time + 1);
        int leave = solve(vec , idx + 1 , time);

        return dp[idx][time] = max(take , leave);  
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp , -1 , sizeof(dp));
        sort(begin(satisfaction) , end(satisfaction));
        return solve( satisfaction , 0 , 1);
    }
};