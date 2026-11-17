class Solution {
public:
    unordered_map<int, vector<int>> adj;
    long long fuel = 0;
    int seats;
    long long solve(int src, int parent) {

        long long people = 1;

        for (auto v : adj[src]) {
            if (v != parent) {
                people += solve(v, src);
            }
        }

 
        if (src != 0) {
            fuel += (people + seats - 1) / seats;
        }

        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int s) {

        seats = s;

        for (auto edge : roads) {
            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        solve(0, -1);

        return fuel;
    }
};