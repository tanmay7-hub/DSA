class Solution {
public:
    int n , goal , k;
    int mod = 1e9 + 7;
    int dp[101][101];
    long long solve(int count , int unique){
        if(count == goal){
            if(unique == n)return 1;
            return 0;
        }
        long long ans = 0;
        
        if(dp[count][unique] != -1 ) return dp[count][unique]; 
        ans += (n - unique) * solve(count + 1 , unique +  1);
        ans %= mod;
        
        if(unique > k ){
           ans += (unique - k) * solve(count + 1 , unique);
           ans %= mod;
        }
        
        return dp[count][unique] = ans % mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp , -1 , sizeof(dp));
        this->goal = goal;
        this->n = n;
        this->k = k;
        return solve(0 , 0);
    }
};