class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({ cost , v});
        }
        this->n = n;
    }

    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];
        adj[u].push_back({ cost , v});
    }
    void dijsktra(int src , int des , vector<int>&dist ){
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0 , src});
       while(!pq.empty()){
           int d = pq.top().first;
           int node = pq.top().second;
           pq.pop();

        //    if(d > dist[node])continue;
           for(auto p : adj[node]){
               if(p.first + d < dist[p.second]){
                  dist[p.second] = p.first + d;
                  pq.push({dist[p.second],p.second});
               }      
           }
       }
    }
    int shortestPath(int node1, int node2) {
        vector<int>dist(n + 1, INT_MAX);
        dist[node1] = 0;
        dijsktra(node1 , node2  , dist );
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */