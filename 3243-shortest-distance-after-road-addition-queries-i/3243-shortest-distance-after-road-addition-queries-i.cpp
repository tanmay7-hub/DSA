class Solution {
public:
    const int INF = 1e9;
    int bfs(unordered_map<int , vector<int>>&adj , int src , int tar){

        queue<int>q;
        vector<bool>vis(adj.size() , false);
        q.push(src);
        
        int level = 0;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
               int curr = q.front();
               q.pop();
               vis[curr] = true;     
               if(tar == curr)return level;
               for(auto v : adj[curr]){
                  if(!vis[v]){
                
                    q.push(v);
                  }
               }
            }
            level++;          
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int , vector<int>> adj;

        for(int i = 0 ; i + 1< n ; i++){
            adj[i].push_back(i + 1);
        }
        vector<int> ans;
        for(auto q : queries){
             int u = q[0];
             int v = q[1];
             

             adj[u].push_back(v);
             int curr = bfs(adj , 0 , n - 1);
             ans.push_back(curr);
        }

        return ans;
    }
};