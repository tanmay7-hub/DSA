
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target,
                    vector<vector<int>>& specialRoads) {

        int n = specialRoads.size();

        auto manhattan = [](int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        };

        int ans = manhattan(start[0], start[1],
                            target[0], target[1]);

        
        vector<int> dist(n, INT_MAX);
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for (int i = 0; i < n; i++) {
            int d = manhattan(
                start[0], start[1],
                specialRoads[i][0], specialRoads[i][1]
            );

            dist[i] = d;
            pq.push({d, i});
        }

     
        while (!pq.empty()) {
            auto [cost, i] = pq.top();
            pq.pop();

            if (cost != dist[i])
                continue;

            int sx = specialRoads[i][0];
            int sy = specialRoads[i][1];
            int ex = specialRoads[i][2];
            int ey = specialRoads[i][3];
            int roadCost = specialRoads[i][4];

            ans = min(ans, cost +
                manhattan(sx, sy, target[0], target[1]));


            int afterRoad = cost + roadCost;

            ans = min(ans, afterRoad +
                manhattan(ex, ey, target[0], target[1]));


            for (int j = 0; j < n; j++) {

                int nsx = specialRoads[j][0];
                int nsy = specialRoads[j][1];

                int newCost = afterRoad +
                    manhattan(ex, ey, nsx, nsy);

                if (newCost < dist[j]) {
                    dist[j] = newCost;
                    pq.push({newCost, j});
                }
            }
        }

        return ans;
    }
};
