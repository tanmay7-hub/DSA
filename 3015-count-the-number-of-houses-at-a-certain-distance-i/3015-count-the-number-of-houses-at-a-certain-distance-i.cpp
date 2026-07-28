class Solution {
public:
    const int INF = 1e9;
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
            if (i + 1 < n) {
                dist[i][i + 1] = 1;
                dist[i + 1][i] = 1;
            }
        }
        dist[x - 1][y - 1] = 1;
        dist[y - 1][x - 1] = 1;
        auto floyd = [&]() {
            for (int via = 0; via < n; via++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (dist[i][via] == INF || dist[via][j] == INF)
                            continue;
                        dist[i][j] =
                            min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        };
        floyd();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                    if (i == j) continue;          
                    ans[dist[i][j] - 1]++;          
            }
        }

        return ans;
    }
};