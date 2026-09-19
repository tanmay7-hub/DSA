class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> dp;

    int solve(int i, int par, int div,
              vector<int>& coins, int k) {

        if (dp[i][div] != -1)
            return dp[i][div];

        int curr_val = coins[i] >> div;

        int op1 = curr_val - k;

        for (int v : adj[i]) {
            if (v == par)
                continue;

            op1 += solve(v, i, div, coins, k);
        }

        if (div + 1 == 15)
            return dp[i][div] = op1;

        int op2 = curr_val >> 1;

        for (int v : adj[i]) {
            if (v == par)
                continue;

            op2 += solve(v, i, div + 1, coins, k);
        }

        return dp[i][div] = max(op1, op2);
    }

    int maximumPoints(vector<vector<int>>& edges,
                      vector<int>& coins,
                      int k) {

        int n = edges.size() + 1;

        adj.assign(n, {});
        dp.assign(n, vector<int>(15, -1));

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return solve(0, -1, 0, coins, k);
    }
};