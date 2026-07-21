class Solution {
public:
    int n;
    bool inCir( int i , int j , vector<vector<int>>& bombs ){
        long long x  = bombs[j][0] - bombs[i][0];
        long long y  = bombs[j][1] - bombs[i][1];
        long long r = bombs[i][2];


        long long dis =  x * x + y * y;
        return dis <= 1LL * r * r;
    }
    int dfs(int  u ,vector<vector<int>>& bombs , vector<bool>&vis){
        vis[u] = true;
        int ans = 0;
        for(int i = 0 ; i < n ; i++ ){
            if(!vis[i] && inCir(u , i , bombs)){
              ans += dfs(i , bombs , vis);
            }
        }
        return ans + 1;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
         n = bombs.size();  
        int ans = 0;
      
        for(int i = 0 ; i < n ; i++ ){
                  vector<bool>vis( n , false);
                ans = max(ans , dfs(i , bombs , vis));    
        }
        return ans;
    }
};