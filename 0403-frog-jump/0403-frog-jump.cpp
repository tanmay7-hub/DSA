class Solution {
public:
    vector<int> stones;
    unordered_map<int , int> mp;
    bool isValid(int i){
        return i >= 0 && i < stones.size();
    }
    int dp[2001][2001];
    bool solve(int idx, int last) {
        if(idx + 1== stones.size()) return true;
        if(idx < 0 || idx >= stones.size()) return false;
        bool ans = false;
        int jump = last;
        
        if(dp[idx][last] != -1) return dp[idx][last];
        if(jump > 0 ){
            int next_pos = stones[idx] + jump;
            if(mp.count(next_pos)){
                ans = ans || solve(mp[next_pos] , jump);
            }
        }
        jump = last - 1; 
        if(jump > 0 ){
            int next_pos = stones[idx] + jump;
            if(mp.count(next_pos)){
                ans = ans || solve(mp[next_pos] , jump);
            }
        }
        jump = last + 1;
        if(jump > 0 ){
            int next_pos = stones[idx] + jump;
            if(mp.count(next_pos)){
                ans = ans || solve(mp[next_pos] , jump);
            }
        }
        return dp[idx][last] = ans;

    }
    bool canCross(vector<int>& stones) {
        this->stones = stones;
        memset(dp , -1 , sizeof(dp));
        for(int i = 0 ; i < stones.size() ;i++){
            mp[stones[i]] = i;
        }
        return solve(0 , 0 );
    }
};