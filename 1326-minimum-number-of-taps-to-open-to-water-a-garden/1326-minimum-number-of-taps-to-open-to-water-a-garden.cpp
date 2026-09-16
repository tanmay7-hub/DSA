class Solution {
public:
    vector<int> ranges;
    vector<int> l , r;
    int n;
    int dp[10001];
    long long solve(int pos){
        if(pos >= n )return 0;
        if(dp[pos] != -1)return dp[pos];
        long long ans = INT_MAX;
        for(int i = 0 ; i <= n ; i++ ){
            if(l[i] <= pos && r[i] > pos){
                ans = min(ans ,1 +  solve(r[i]));
            }
        }
        return dp[pos] = ans;
    }
    int minTaps(int n, vector<int>& ranges) {
        this->ranges = ranges;
        this->n = n; 
        memset(dp , -1 , sizeof(dp));
        l.resize(n + 1);
        r.resize(n + 1);
        for(int i = 0 ; i <= n ; i++ ){
            l[i] = max(0 , i - ranges[i]);
            r[i] = min(n , i + ranges[i]);
        }
        int ans = solve(0 );
        return ans == INT_MAX ? -1 : ans;
    }
};