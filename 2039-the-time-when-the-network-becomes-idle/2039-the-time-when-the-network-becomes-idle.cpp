class Solution {
public:
    unordered_map<int , vector<int>> adj;

    vector<int> dijsktra(int src , int n){
       
       vector<int> dist(n , INT_MAX);
       dist[src] = 0;
       
       queue<int> q;
       q.push(src);

       while(!q.empty()){
            
         int curr = q.front();
         q.pop();


         for(auto v : adj[curr]){
            if(dist[curr] + 1 < dist[v] ){
                dist[v] = dist[curr] + 1;
                q.push(v);
            }
         }
       }

       return dist;
    }
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        for(auto edge : edges){
            int u = edge[0] , v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        } 

        vector<int> dist = dijsktra(0 , n );

        int tm = -1 ;
        for(int i = 1 ; i < n ; i++ ){
            int curr_time = dist[i] * 2;

            if(curr_time > patience[i]){
               int nodes = (curr_time - 1) / patience[i] ;

               tm = max(tm , curr_time + (nodes ) * patience[i] );
            }else{
                tm = max(tm , curr_time);
            }

        }
        return tm + 1; 
    }
};