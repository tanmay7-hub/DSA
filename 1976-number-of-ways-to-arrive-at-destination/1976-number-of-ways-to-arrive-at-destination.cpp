class Solution {
public:
    int n;
    int MOD = 1e9 + 7;
    typedef long long ll;
    typedef   pair< ll , ll >   P; 
    unordered_map<int , vector<pair<int , int>>> adj;

    int dijsktra(int src , int des  ) {
       priority_queue< P , vector<P> , greater<P>> pq;

       vector<int> ways(n , 0);
       vector<ll> dist(n , LLONG_MAX);

       pq.push({0 , src});
       ways[src] = 1 , dist[src] = 0; 

       while(!pq.empty()){
          auto curr = pq.top();
          ll d = curr.first ;
          int  u = curr.second;
          pq.pop();
          
          if( d > dist[u] )continue;
          for(auto &ngh: adj[u]){
             int v = ngh.second;
             ll wt = ngh.first;
             if(dist[u] + wt < dist[v]){

                dist[v] = dist[u] + wt;
                ways[v] = ways[u];
                pq.push({dist[v] , v});

             }else if(dist[u] + wt == dist[v]){    
                ways[v] = ( ways[v] + ways[u] ) % MOD;
             }
          }
       }
       return ways[des];   

    }
    int countPaths(int n, vector<vector<int>>& roads) {
        this->n = n;
        for(auto road : roads){
            int u = road[0] , v = road[1] , wt = road[2];
            adj[u].push_back({wt , v});
            adj[v].push_back({wt , u});
        }
        vector<bool> visited(n , false);
        int ans = dijsktra(0  , n - 1 );
        return ans;
    }
};