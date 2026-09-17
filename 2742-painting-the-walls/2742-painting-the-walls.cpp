class Solution {
public:
    vector<int> cost, time;
    int dp[501][501];
    int n;
    int solve(int i, int wall) {
        if (wall <= 0)
            return 0;
        if (i >= n)
            return INT_MAX;

            if(dp[i][wall] != -1)return dp[i][wall];
        int take = solve(i + 1, wall - time[i] - 1);
        if (take != INT_MAX){
            take += cost[i];
        }
        int skip = solve(i + 1, wall);

        return dp[i][wall] = min(take, skip);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
         memset(dp, -1, sizeof(dp));
        this->cost = cost;
        this->time = time;
        n = cost.size();
        return solve(0, n);
    }
};