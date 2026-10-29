class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    long long dp[40001];
    int mod = 1e9+7;
    long long solve(int src, int dest, vector<int>& dist) {
        if (src == dest)
            return 1;

        long long ans = 0;
        if(dp[src] != -1)return dp[src];

        for (auto [wt , v] : adj[src]) {

            if (dist[v] < dist[src]) {
                ans = (ans + solve(v, dest, dist)) % mod;
            }
        }
        return dp[src] = ans % mod;
    }
    void dijkstra(int src, vector<int>& dist) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, src});

        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();

            if (wt > dist[u])
                continue;

            for (auto& [w, v] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        memset(dp , -1 , sizeof(dp));
        adj.resize(n + 1);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];

            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        vector<int> dist(n + 1, INT_MAX);

        dist[n] = 0;
        dijkstra(n, dist);

        return solve(1, n, dist);
    }
};