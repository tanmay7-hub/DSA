class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {

        int n = friends.size();
        int curr_level = 0;
        queue<int> q;
        q.push(id);
        vector<bool> vis(n, false);
        vis[id] = true;
        while (!q.empty()) {
            int sz = q.size();
            if (curr_level == level)
                break;
            while (sz--) {

                int curr_node = q.front();
                q.pop();

                for (auto v : friends[curr_node]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            curr_level++;
        }

        unordered_map<string, int> mp;
        vector<string> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto ch : watchedVideos[node]) {
                if (mp.find(ch) == mp.end()) {
                    ans.push_back(ch);
                }
                mp[ch]++;
            }
        }

        sort(ans.begin(), ans.end(), [&](string c1, string c2) {
            if (mp[c1] != mp[c2])
                return mp[c1] < mp[c2];

            return c1 < c2;
        });
        return ans;
    }
};