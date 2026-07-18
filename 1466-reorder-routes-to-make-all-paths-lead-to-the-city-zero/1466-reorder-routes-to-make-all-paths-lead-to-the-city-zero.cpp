class Solution {
public:
    int ans = 0;
    void dfs(int root ,int par,  unordered_map<int,vector<pair<int,int>>>&mp ) {
         
         for(auto [v , dir] : mp[root]){
            if(v == par){
                ans += dir;
            }
            else  dfs(v , root , mp); 
         }

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto c : connections){
            int u = c[0];
            int v = c[1];

            mp[u].push_back({v , 0});
            mp[v].push_back({u , 1});
        }
        // vector<int>visited(n,false);
        dfs(0 , -1 , mp );
        return ans;
    }
};