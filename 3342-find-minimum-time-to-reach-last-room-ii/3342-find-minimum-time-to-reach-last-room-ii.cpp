class Solution {
public:
    int n, m;
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    using P =  pair<int, pair<pair<int, int>, int>> ;

    bool valid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }
    int solve(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(3, INT_MAX)));
        priority_queue< P, vector<P>, greater<P>> q;

        q.push({0, {{0, 0}, 1}});
        dist[0][0][1] = 0;
        while (!q.empty()) {

            auto [t, state] = q.top();
            q.pop();

            auto [pos, alt] = state;
            auto [i, j] = pos;

            if (i == n - 1 && j == m - 1)
                return t;

            for (auto v : dir) {
                int new_i = i + v[0];
                int new_j = j + v[1];

                if (valid(new_i, new_j)) {
                    long long newTime = max(t, grid[new_i][new_j]) + alt;
                    int nextAlt = 3 - alt;
                    if (newTime < dist[new_i][new_j][nextAlt]) {
                        dist[new_i][new_j][nextAlt] = newTime;
                        q.push({newTime, {{new_i, new_j}, nextAlt}});
                    }
                }
            }
        }
        return -1;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        return solve(moveTime);
    }
};