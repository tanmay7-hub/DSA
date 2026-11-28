class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1) {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;

        vector<vector<pair<int, long long>>> adj(n);


        for (auto& edge : conversions) {
            int u = edge[0];
            int v = edge[1];
            long long wt = edge[2];

            long long inv = modPow(wt, MOD - 2);

            adj[u].push_back({v, wt});
            adj[v].push_back({u, inv});
        }

        vector<long long> ans(n, 0);
        vector<bool> visited(n, false);

        queue<int> q;

        ans[0] = 1;
        visited[0] = true;

        q.push(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& [v, wt] : adj[u]) {
                if (!visited[v]) {
                    ans[v] = (ans[u] * wt) % MOD;

                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            result[i] = ans[i];
        }

        return result;
    }
};