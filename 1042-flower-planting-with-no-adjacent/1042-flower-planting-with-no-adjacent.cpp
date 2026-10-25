class Solution {
public:
    vector<vector<int>> adj;
    // void dfs(vector<bool>& vis , int node , vector<int>& ans){
      
    //   int bitMask = 0;
    //   vis[node] = true;
    //   for(auto v : adj[node]){

    //   }
    // }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        adj.resize(n + 1);
        for(auto edge : paths){
            int u = edge[0] , v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans( n  , -1);
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++) {
            int mask = 0;

            for (auto v : adj[i]) {
                if (ans[v - 1] != -1) {
                    mask |= (1 << (ans[v - 1] - 1));
                }
            }

            for (int j = 1; j <= 4; j++) {
                if ((mask & (1 << (j - 1))) == 0) {
                    ans[i - 1] = j;
                    break;
                }
            }
        }
        
        return ans;
    }
};