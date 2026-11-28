class Solution {
public:

    int find(int x, vector<int>& par) {
        if (par[x] == x) return x;

        return par[x] = find(par[x], par);
    }

    bool unite(int a, int b,
               vector<int>& rank,
               vector<int>& par) {

        int par_a = find(a, par);
        int par_b = find(b, par);

        if (par_a == par_b) return false;

        if (rank[par_a] > rank[par_b]) {
            par[par_b] = par_a;
        }
        else if (rank[par_b] > rank[par_a]) {
            par[par_a] = par_b;
        }
        else {
            rank[par_a]++;
            par[par_b] = par_a;
        }

        return true;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {

      
        sort(edges.begin(), edges.end(),
             [](const auto& a, const auto& b) {
                 return a[2] < b[2];
             });

        vector<int> par(n);
        vector<int> rank(n, 1);

        iota(par.begin(), par.end(), 0);

        int components = n;

        if (components <= k) return 0;

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (unite(u, v, rank, par)) {
                components--;
            }

            if (components <= k) {
                return w;
            }
        }

        return 0;
    }
};