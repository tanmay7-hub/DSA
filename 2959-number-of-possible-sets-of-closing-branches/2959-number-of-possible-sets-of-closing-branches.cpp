class Solution {
public:
    const int INF = 1e9;
    bool solve(int n, int mx, vector<vector<int>>& roads,
               unordered_set<int>& s) {
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            if (s.count(i))
                dist[i][i] = 0;
        }
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            if (!s.count(v) || !s.count(u))
                continue;

            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (dist[i][via] == INF || dist[via][j] == INF)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!s.count(i))
                continue;

            for (int j = 0; j < n; j++) {
                if (!s.count(j))
                    continue;

                if (dist[i][j] > mx)
                    return false;
            }
        }
        return true;
    }
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            unordered_set<int> s;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    s.insert(i);
            }

            if (solve(n, maxDistance, roads, s))
                ans++;
        }
        return ans;
    }
};