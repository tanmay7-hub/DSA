class Solution {
public:
    int comp = 0;
    vector<vector<int>> adj;
    long long solve( int src , vector<int> & values , int k , int par){
        long long sum = values[src];

        for(auto v : adj[src]){
            if(par != v )
               sum += solve(v , values , k , src);
        }
        

        if(sum % k == 0 ){
            comp++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
         
         adj.resize(n );

         for(auto edge : edges ){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
         }
         solve( 0 , values , k , -1);

         return comp;
    }
};