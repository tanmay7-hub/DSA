class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0] , v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_set<int> s;
        for(auto node : restricted){
            s.insert(node);
        }
        vector<bool> vis(n , false);
        queue<int> q;

        q.push(0);
        vis[0] = true;
        int ans = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            ans += 1;

            for(auto v : adj[curr]){
                if(!vis[v] && s.find(v) == s.end()){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};