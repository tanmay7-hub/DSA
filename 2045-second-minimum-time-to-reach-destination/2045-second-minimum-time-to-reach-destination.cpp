class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int n;
    int solve(int src, int des, int time, int change) {
        vector<vector<int>> dist(n + 1 , vector<int> (2,INT_MAX));
        queue<pair<int , int>> q;
        q.push({0 , src});
        while(!q.empty()){
            pair<int , int > curr = q.front();
            q.pop();
             int d = curr.first;
             int u = curr.second;
            for(int v : adj[u]){
                if(d + 1 < dist[v][0]){
                   dist[v][1] = dist[v][0];
                   dist[v][0] = d + 1;
                   q.push({d + 1 , v});
                }else if(d + 1  > dist[v][0] && d + 1< dist[v][1]){
                   dist[v][1] = d + 1;
                   q.push({d + 1 , v});
                }
            }
        }

        int edgeTaken = dist[des][1];
        int currTime = 0;
        for(int i = 0 ; i < edgeTaken ; i++ ){
             
             if((currTime / change) % 2 == 1 ){
                currTime += change - (currTime % change);
             }

             currTime += time;
        }

        return currTime;
        
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
         this->n = n;
        for (auto edge : edges) {
            int u = edge[0] , v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return solve(1, n, time, change);
    }
};