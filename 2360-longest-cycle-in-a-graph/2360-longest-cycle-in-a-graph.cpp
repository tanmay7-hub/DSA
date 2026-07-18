class Solution {
public:
    int ans = -1;

    void dfs(int node , vector<int>& edges , vector<bool>&visited ,vector<bool>&inRecursion ,vector<int>&count){       
           inRecursion[node] = true;
           visited[node] = true;

           int v = edges[node];

           if(v != -1 && !visited[v]){
              count[v] = count[node] + 1;
              dfs(v , edges , visited ,inRecursion, count);
           }

           if(v  != - 1 && visited[v] && inRecursion[v]){
             ans = max(ans , count[node] - count[v] + 1 );
           }

          inRecursion[node] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool>visited(n , false);
        vector<bool>inRecursion(n , false);
         vector<int>count(n , 1);
        for(int i = 0 ; i < n ; i++ ){
            if(!visited[i]){
               
                dfs(i , edges ,visited  , inRecursion , count);
            }
        }
        return ans ;
    }
};