class Solution {
public:
    int dfs(int node, int k, int sum, int t, vector<vector<pair<int, int>>>& graph, vector<vector<unordered_map<int, int>>>& memo) {
        if (k == 0) return sum < t ? sum : -1;
        if (memo[node][k].count(sum)) return memo[node][k][sum];

        int maxSum = -1;
        for (auto& [neighbor, weight] : graph[node]) {
            int newSum = sum + weight;
            if (newSum >= t) continue;
            int result = dfs(neighbor, k - 1, newSum, t, graph, memo);
            if (result != -1)
                maxSum = max(maxSum, result);
        }

        return memo[node][k][sum] = maxSum;
    }
    
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {   
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].emplace_back(v, w);
        }

        vector<vector<unordered_map<int, int>>> memo(n, vector<unordered_map<int, int>>(k + 1));
        int ans = -1;

        for (int i = 0; i < n; ++i) {
            int res = dfs(i, k, 0, t, graph, memo);
            ans = max(ans, res);
        }

        return ans;
    }
};