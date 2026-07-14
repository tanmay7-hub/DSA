class Solution {
public:
    vector<vector<int>>adj;
    vector<vector<int>>ans;
    vector<int>curr;
    int n;
    
    void dfs(int u){
          
        curr.push_back(u);
         if(u == n - 1){
            ans.push_back(curr);            
         }
         for( auto v : adj[u] ){    
                dfs(v );
         }

         curr.pop_back();
        
    }
   
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->adj = graph;
        n = graph.size();
        dfs(0);
         return ans;
    }
};