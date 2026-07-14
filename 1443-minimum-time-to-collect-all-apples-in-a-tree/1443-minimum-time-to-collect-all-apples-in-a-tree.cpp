class Solution {
public:
    vector<bool>ap;
    vector<vector<int>>adj;
    vector<bool>vis;
    int dfs(int u ){
       vis[u] = true ;
       int ans = 0;
       for(auto v : adj[u]){
          if(!vis[v]){
             int costCh = dfs(v);
             ans += (ap[v] || costCh ? 2 : 0) + costCh;
          }
       }

       return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        vector<vector<int>>adj(n );
        vis = vector<bool>(n,false);
        for( auto edge : edges ) {
             int u = edge[0];
             int v = edge[1];

             adj[u].push_back(v);
             adj[v].push_back(u);
        }
        this->adj = adj; 
        ap = hasApple;
        return dfs(0);

               
    }
};