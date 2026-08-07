class Solution {
public:
    unordered_map< int , vector<int>> adj;
    unordered_map< int , int > bobTime;
    bool dfs(int src , int t , vector<bool> & vis){
        vis[src] = true;
       
        if(src == 0){
             bobTime[src] = t;
             return true;
        }
        for(auto v : adj[src]){
            if(!vis[v]){
                if(dfs(v , t + 1 , vis)){
                    bobTime[src] = t ;
                    return true;
                }
            }
        }
        return false;
    }
    int dfsAlice(int src ,int t, vector<bool> &visited , vector<int> &amt){
       visited[src] = true;
       bool isLeaf = true;
       int ans = INT_MIN;
       for( auto v : adj[src] ){
            if(!visited[v]){
                isLeaf = false;
               ans = max(ans , dfsAlice(v ,t + 1 , visited , amt));
            }
       }
       bool check = bobTime.count(src);

       if(isLeaf ) ans = 0;
       if(!check || t < bobTime[src]){
           ans += amt[src];
       }else if( t == bobTime[src]){
           ans += amt[src] / 2;
       }
       return ans ;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        for(auto edge : edges ){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n , false);
        dfs(bob , 0 , visited);


        visited.assign(n , false);

        int ans = dfsAlice(0 ,0 , visited , amount );
        return ans;
    }
};