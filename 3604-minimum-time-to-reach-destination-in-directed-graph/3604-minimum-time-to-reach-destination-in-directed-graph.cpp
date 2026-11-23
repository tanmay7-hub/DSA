class Solution {
public:
    vector<vector<array<int, 3>>> adj;
    int dijsktra(int src , int dest , int n){
        
        using state = pair<int ,int >;
        priority_queue<
             state ,
             vector<state> ,
             greater<state>
        >pq;

        vector<int> dist(n, INT_MAX);
        dist[src] = 0; 

        pq.push({0 , 0});
        while(!pq.empty()){

            state curr = pq.top();
            int u = curr.second , t = curr.first ;
            pq.pop();

            if(u == dest)return t;

            for(auto [v , st , end] : adj[u]){
                  
                
                  if(t >= st && t  <= end){
                    if(dist[v] > t + 1){
                        dist[v] = t + 1;
                         pq.push({ t + 1 , v});
                    }
                  }else if(t < st){
                    if(dist[v] > st + 1) {
                        dist[v] = st + 1;
                         pq.push({st + 1 , v});
                    }
                  }
            }
        }

        return -1;
    }
    int minTime(int n, vector<vector<int>>& edges) {
        adj.resize(n);

        for(auto &edge : edges){
            int u   = edge[0];
            int v   = edge[1];
            int st  = edge[2];
            int end = edge[3];

           adj[u].push_back({v , st , end});
        }

        return dijsktra(0 , n - 1  , n );
    }
};