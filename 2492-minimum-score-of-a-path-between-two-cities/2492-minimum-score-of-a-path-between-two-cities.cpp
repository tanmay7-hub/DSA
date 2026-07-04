class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>mp;
    vector<bool>vis;
    int ans = INT_MAX;
    int n;
    void dfs(int node ){
         
         vis[node] = true;
         
         for(auto& [v,dis] : mp[node]){
            ans = min (ans,dis);
            if(!vis[v])dfs(v ); 
         }

    }
    int minScore(int n, vector<vector<int>>& roads) {
        vis.resize(n + 1,false);
        this->n = n;
         for(auto &vec : roads){
            int u   = vec[0];
            int v   = vec[1];
            int dis = vec[2];

            mp[u].push_back(make_pair(v,dis));
            mp[v].push_back(make_pair(u,dis));
          }
           
         
        dfs(1); 
         return ans;
    }
};