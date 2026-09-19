class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int node, int cuts, vector<int> &coins,vector<vector<int>> &adjL,int parent,int k)
    {
        if(dp[node][cuts]!=-1) return dp[node][cuts];
        int val = coins[node] >> cuts;
        int normal = val-k;
        for(int v : adjL[node])
        {
            if(v!=parent) normal+=dfs(v,cuts,coins,adjL,node,k);
        }
        int special = val/2;
        if(cuts+1==15) return dp[node][cuts]=normal; // After 15 cuts, the coin value becomes 0 according to the constraints,
        // so there is no benefit in considering more cuts.
        for(int v : adjL[node])
        {
            if(v!=parent)
            {
                special+= dfs(v,cuts+1,coins,adjL,node,k);
            }
        }
        return dp[node][cuts] = max(normal,special);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = edges.size()+1;
        dp.assign(n,vector<int>(15,-1)); // 15 cuts are enough according to the constraints
        vector<vector<int>> adjL(n);
        for(auto &e : edges)
        {
            adjL[e[0]].push_back(e[1]);
            adjL[e[1]].push_back(e[0]);
        }
        return dfs(0,0,coins,adjL,-1,k); // max profit for tree rooted at 0 with 0 cuts
    }
};