class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        unordered_map<int , vector<int>> adj;

        for(auto edge :edges){
            int u = edge[0] , v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MIN;
        for(int i = 0 ; i < vals.size() ; i++ ){
            priority_queue<int, vector<int>, greater<int>> pq;
            for(auto v : adj[i]){
                if(vals[v] > 0 ){
                    pq.push(vals[v]);
                }

                if(pq.size() > k ) {
                    pq.pop();
                }
            }
            int curr = vals[i];
            while(!pq.empty()){
                curr += pq.top();
                pq.pop();
            }
        
            ans = max(ans , curr );
        }

        return ans;
    }
};