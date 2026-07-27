class Solution {
public:
    const int INF = 1e9; 
    unordered_map<char ,vector<pair<int,char>>>adj;
    void solve(vector<vector<int>>&dist ){
        
        for(int i = 0 ; i < dist.size() ; i++ )
              dist[i][i] = 0;

        for(int via = 0 ; via < 26 ; via++){
            for(int i = 0 ; i < 26 ; i++){
                for(int j = 0 ; j < 26 ; j++ ){

                    if(dist[i][via] == INF || dist[via][j] == INF) continue;

                    dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>dist(26 , vector<int>(26, INF));
        for(int i = 0 ; i < original.size() ; i++ ){
            char u = original[i];
            char v = changed[i];
            int  w = cost[i];
            adj[u].push_back({w , v});
            dist[u - 'a'][v - 'a'] =  min( dist[u - 'a'][v - 'a'] , w );
        }
        
        long long ans = 0;
        
        solve(dist);
        for(int i = 0 ; i < source.size() ; i++ ){
            char src = source[i];
            char tar = target[i];

            if(src == tar)continue;

            
            long long curr = dist[src - 'a'][tar - 'a'];
            if(curr == INF)return -1;
            ans +=curr;
        }

        return ans;

    }
};