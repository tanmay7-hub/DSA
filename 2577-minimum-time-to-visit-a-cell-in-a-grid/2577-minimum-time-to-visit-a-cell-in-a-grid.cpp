class Solution {
public:
    int n, m;
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
#define P pair<int, pair<int, int>>

    bool valid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }
    int solve(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, {0, 0}}); // time , i , j ;

        while (!q.empty()) {

            P nd = q.top();
            int t = nd.first, i = nd.second.first, j = nd.second.second;
            q.pop();

            if (i == n - 1 && j == m - 1)
                return t;

            for (auto v : dir) {
                int new_i = i + v[0];
                int new_j = j + v[1];

                if (valid(new_i, new_j)) {
                    int num = grid[new_i][new_j];
                    int newTime;
                    if (num <= t + 1)
                        newTime = t + 1;
                    else {
                        int wait = num - (t + 1);
                        if (wait % 2 == 0)
                            newTime = num;
                        else
                            newTime = num + 1;
                    }
                    if (newTime < dist[new_i][new_j]) {
                        dist[new_i][new_j] = newTime;
                        q.push({newTime, {new_i, new_j}});
                    }
                }
            }
        }
        return -1;
    }
    int minimumTime(vector<vector<int>>& grid) { return solve(grid); }
};