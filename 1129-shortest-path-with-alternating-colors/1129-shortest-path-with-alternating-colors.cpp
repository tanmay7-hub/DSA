class Solution {
    struct state{
        int node ; int col ; int dist;
        state(int node , int col , int dist){
            this->node = node ;
            this->col = col ;
            this->dist = dist;
        }
    };
public:
    vector<vector<pair<int, int>>> adj;
    int bfs(int n, int src , int dest ){
        queue<state> q;
        vector<vector<int>> dist(n, vector<int>(2, -1));

        q.push(state(0 , -1 , 0));

        while(!q.empty()){

            state curr = q.front();
            q.pop();

            
            if(curr.node == dest){
                return curr.dist;
            }
            for(auto it : adj[curr.node]){
                int next_col = it.second;
                int next_node = it.first;
                
                if (next_col == curr.col) {
                    continue;
                }

                if (dist[next_node][next_col] != -1) {
                    continue;
                }

                dist[next_node][next_col] = curr.dist + 1;

                q.push(state(next_node, next_col, curr.dist + 1));

            }
        }

        
        return -1;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        adj.assign(n , vector<pair<int,int>>());
        for(auto edge : redEdges){
            int col = 0 ;
            int u = edge[0] , v = edge[1];
            adj[u].push_back({v , col});
        }
        for(auto edge : blueEdges){
            int col = 1 ;
            int u = edge[0] , v = edge[1];
            adj[u].push_back({v , col});
        }

        vector<int> ans( n , -1);
        for(int i = 0 ; i < n ; i++ ){
            ans[i] = bfs(n , 0 , i );
        }


        return ans;
    }
};