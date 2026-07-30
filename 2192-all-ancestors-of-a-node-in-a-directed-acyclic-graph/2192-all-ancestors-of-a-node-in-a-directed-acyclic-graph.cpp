class Solution {
public:
    unordered_map<int , vector<int>>adj;
    void dfs(int src , vector<vector<int>>&ans , int num ,vector<int>&vis){
        vis[src] = 1;
        for(auto v : adj[src]){
           if(vis[v] != 1) dfs(v , ans , num , vis);
        }
        if(src != num){
            ans[src].push_back(num);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<vector<int>>ans(n,vector<int>());
       for(int i = 0 ; i < n ; i++ ){
           vector<int> vis(n, 0);
           dfs(i ,ans ,i , vis);
       }
       return ans;
    }
};