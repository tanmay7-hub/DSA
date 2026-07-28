class Solution {
public:
    const int INF = 1e9;
    unordered_map<int, vector<pair<int, int>>> adj;
    int dis;
    void dijsktra(int src, vector<int>& dist) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, src});
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto p : adj[node]) {
                if (p.first + d < dist[p.second]) {
                    dist[p.second] = p.first + d;
                    pq.push({dist[p.second], p.second});
                }
            }
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u});
        }
        vector<int> src(n, INF);
        vector<int> des(n, INF);
        des[n - 1] = 0;
        src[0] = 0;
        dijsktra(0, src);
        dijsktra(n - 1, des);

        dis = src[n - 1];
        vector<bool> ans;

        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            int wt = edge[2];
            bool c = (src[u] + wt + des[v] == dis) || (src[v] + wt + des[u] == dis);
            ans.push_back(c);
        }
        return ans;
    }
};