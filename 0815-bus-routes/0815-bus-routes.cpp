class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src,
                              int target) {
                                if(src == target)return 0;
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < routes.size(); i++) {
            for (auto u : routes[i]) {
                adj[u].push_back(i);
            }
        }
        int n = routes.size();
        queue<int> q;
        vector<bool> visited(n, false);

        for (auto route : adj[src]) {
            q.push(route);
            visited[route] = true;
        }
        int ans = 1 ;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int route = q.front();
                visited[route] = true;
                q.pop();

                for (auto stop : routes[route]) {
                    if(stop == target)return ans;
                    for(auto nextRoute : adj[stop]){
                        if(!visited[nextRoute]){
                            q.push(nextRoute);
                            visited[nextRoute] = true;
                        }
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};