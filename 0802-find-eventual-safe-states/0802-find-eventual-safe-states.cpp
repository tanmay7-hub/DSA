class Solution {
public:
    bool dfs(int node , vector<vector<int>>& graph , vector<bool>&vis , vector<bool>&inRec){
          inRec[node] = true;
          vis[node] = true;

          for(auto &v : graph[node]){
            if(!vis[v]){
               bool curr = dfs(v , graph ,vis , inRec );
               if(curr)return true;
            }else if( inRec[v]){
                return true;
            }
          }
          inRec[node] = false;
          return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>vis(n , false);
        vector<bool>inRec(n , false);
        
        for(int i = 0 ; i < n ; i++ ){
            if(!vis[i]){
                dfs(i ,  graph , vis , inRec);
            }
        }
        vector<int>ans;

        for(int i = 0 ; i < n ; i++){
            if(!inRec[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};