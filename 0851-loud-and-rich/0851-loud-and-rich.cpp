class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    int dfs(int node, vector<int>& quiet) {
        if (ans[node] != -1) {
            return ans[node];
        }

        ans[node] = node;

        for (int v : adj[node]) {
            int candidate = dfs(v, quiet);

            if (quiet[candidate] < quiet[ans[node]]) {
                ans[node] = candidate;
            }
        }

        return ans[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        adj.resize(n);
        ans.assign(n , -1);
        for (auto edge : richer) {
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            dfs(i , quiet);
        }

        
        return ans;
    }
};