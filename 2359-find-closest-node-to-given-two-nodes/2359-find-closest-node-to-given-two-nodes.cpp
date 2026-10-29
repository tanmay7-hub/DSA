class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        int curr = node1;
        int d = 0;
        while (curr != -1 && dist1[curr] == -1) {
            dist1[curr] = d++;
            curr = edges[curr];
        }

        curr = node2;
        d = 0;
        while (curr != -1 && dist2[curr] == -1) {
            dist2[curr] = d++;
            curr = edges[curr];
        }

        int ans = -1;
        int best = INT_MAX;

        for (int i = 0; i < edges.size(); i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int candidate = max(dist1[i], dist2[i]);

                if (candidate < best) {
                    best = candidate;
                    ans = i;
                }
            }
        }

        return ans;
    }
};