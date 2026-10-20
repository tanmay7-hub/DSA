class Solution {
public:
    vector<vector<int>> adj;
    bool solve(int u , string& colors , vector<bool>& vis){
        vis[u] = true;
        char ch = colors[u];
        int count = 0;
        char nextColor = ch == 'R' ? 'B' : (ch == 'B'? 'W' : 'R'); 
        for(auto v : adj[u]){
            if(!vis[v] ){
                count++;
                if(count > 2)return false;
                if(colors[v] == colors[u] || colors[v] != nextColor)return false; 
               if(!solve(v , colors , vis)){
                  return false;
               }
            }
        }

        if(count > 2) return false;
        return true;

    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        adj.assign(n , {});
        vector<bool> canBeRoot( n , true);
        unordered_map<char , char> mp = {{'R' , 'B'} , {'B' , 'W'} , {'W' , 'R'}};
        for(auto &edge : edges){
            int u = edge[0] , v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            if(colors[u] == colors[v]){
                canBeRoot[u] = false;
                canBeRoot[v] = false;
            }
            else if(mp[colors[u]] != colors[v]){
                canBeRoot[u] = false;
            }else if(mp[colors[v]] != colors[u]){
                canBeRoot[v] = false;
            }
        }
        vector<bool>vis;
        for(int i = 0 ; i < n ; i++ ){       
            if(canBeRoot[i]){
                vis.assign(n , false);
                if(solve(i , colors , vis))
                   return i;
            }
        }

        return -1;
    }
};