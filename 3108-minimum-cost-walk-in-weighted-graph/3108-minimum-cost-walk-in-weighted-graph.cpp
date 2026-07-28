class Solution {
public:
    const int INF = 1e9;
    vector<int> par;
    vector<int> rank;
    int find(int x) {
        if (par[x] == x)
            return x;

        return par[x] = find(par[x]);
    }

    void unite(int a, int b) {
        int par_a = find(a);
        int par_b = find(b);

        if (par_a == par_b)
            return;

        if (rank[par_a] > rank[par_b]) {
            par[par_b] = par_a;
        } else if (rank[par_a] < rank[par_b]) {
            par[par_a] = par_b;
        } else {
            par[par_b] = par_a;
            rank[par_a]++;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges , vector<vector<int>>& query) {
        unordered_map<int, int> mp;
        par.resize(n);
        rank.resize(n, 0);
        iota(begin(par), end(par), 0);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            unite(u, v);
        }
        for (auto& e : edges) {
            int root = find(e[0]);

            if (mp.count(root))
                mp[root] &= e[2];
            else
                mp[root] = e[2];
        }
        vector<int> ans;

        for (auto q : query) {
            int par_a = find(q[0]);
            int par_b = find(q[1]);
            if (par_a != par_b) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(mp[par_a]);
        }

        return ans;
    }
};