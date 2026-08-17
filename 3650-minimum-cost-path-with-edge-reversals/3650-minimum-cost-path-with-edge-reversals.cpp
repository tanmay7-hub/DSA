class Solution {
public:

    using P = pair<int,int> ; 
    int dijsktra(vector<vector<P>> &adj , int src , int des){
        int n = adj.size();
        vector<int> dist(n , INT_MAX);
        dist[src] = 0;
        
        priority_queue< P ,vector<P> , greater<P>> pq;  // wt , node;
        pq.push({0 , src});

        while(!pq.empty()){
            auto [dis , u] = pq.top();
            
            pq.pop();

            for(auto [wt , v] : adj[u]){
                if( dis + wt  < dist[v]){
                    dist[v] = dis + wt;

                    pq.push({dist[v] , v});
                }
            }
        }
        return dist[des] == INT_MAX ? -1 : dist[des];
        
    }
    int minCost(int n, vector<vector<int>>& edges) {
        
        vector<vector<P>> adj(n);
        for(auto edge : edges ){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({wt , v});
            adj[v].push_back({2 * wt , u});
        }

        return dijsktra(adj , 0 , n - 1);
    }
};