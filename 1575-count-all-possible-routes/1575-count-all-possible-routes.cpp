class Solution {
public:
    int finish;
    long long dp[101][201];
    int mod = 1e9 + 7;
    long long solve(vector<int>& locations , int curr , int fuel){
           if(fuel < 0 )return 0;
           if(dp[curr][fuel] != -1) return dp[curr][fuel];
           long long ans = curr == finish ;
           for(int i = 0 ; i < locations.size() ; i++ ){
                if(i == curr)continue;            
                    ans += solve(locations , i , fuel - abs(locations[i] - locations[curr])) % mod;
           }

           return dp[curr][fuel] = ans % mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        this->finish = finish;
        memset(dp , -1 , sizeof(dp));
        return solve(locations , start , fuel) % mod;
    }
};