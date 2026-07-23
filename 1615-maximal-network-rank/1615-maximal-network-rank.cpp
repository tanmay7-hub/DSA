class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>>adj;
        vector<vector<bool>>isConn(n , vector<bool>( n , false ) );
        for(int i = 0 ; i < n ; i++) isConn[i][i] = true;
        for(auto edge : roads){
            int u = edge[0];
            int v = edge[1];
            isConn[u][v] = true;
            isConn[v][u] = true;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans = 0;

        for(auto edge : roads){
            int u = edge[0];
            int v = edge[1];
            int src_edge = adj[u].size();
            int des_edge = adj[v].size();

            ans = max({ans ,src_edge , des_edge , src_edge + des_edge - 1});
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ;j++ ){
                if(!isConn[i][j]){
                    int src_edge = adj[i].size();
                    int des_edge = adj[j].size();
                    ans = max({ans  , src_edge +  des_edge});
                }
            }
        }
        return ans;
    }
};