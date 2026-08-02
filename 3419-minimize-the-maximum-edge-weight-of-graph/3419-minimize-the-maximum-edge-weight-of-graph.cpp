class Solution {
public:
    void dfs(vector<vector<int>>& adj , vector<bool> &vis , int src ){
        vis[src] = true;
        for(auto v : adj[src]){
            if(!vis[v]){
                dfs(adj , vis , v);
            }
        }
    }
    bool check(int n , int mid , vector<vector<int>>& edges){
        vector<vector<int>>adj(n);
        for(auto& edge : edges){
            int u  = edge[1];
            int v  = edge[0];
            int wt = edge[2];

            if(wt <= mid){
                adj[u].push_back(v);
            }
        }

        vector<bool>vis(n , false);
        dfs(adj , vis , 0);

        for(auto isVis : vis){
            if(!isVis)return false;
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        
        int mxWt ;
        for(auto& edge :edges){
             mxWt = max(mxWt , edge[2]);
        }

        int st = 0 , end = mxWt;
        int ans = -1;
        while(st <= end){
            int mid = st + ( end - st ) / 2;

            if(check(n , mid , edges)){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
};