class Solution {
public:
    unordered_map<char , vector<int>> mp;
    string ring , key;
    int n ;
    int dp[101][101];
    int solve(int key_idx  , int ring_idx){
        if(key_idx == key.size()) return 0;
        
        if(dp[key_idx][ring_idx] != -1)return dp[key_idx][ring_idx];
        char curr_ch = key[key_idx];
        int ans = INT_MAX;
        for(int next_idx : mp[curr_ch]){
           int  dist =  min(abs(ring_idx - next_idx) , n - abs(ring_idx - next_idx));
           ans = min(ans , 1 + dist + solve(key_idx + 1 , next_idx));
        }

        return dp[key_idx][ring_idx] = ans;
       
    }
    int findRotateSteps(string ring, string key) {
        memset(dp , -1 , sizeof(dp));
        this->ring = ring;
        this->key  = key;
        this->n = ring.size();

        for(int i = 0 ; i < ring.size() ; i++ ){
            char ch = ring[i];
            int idx = i;
            mp[ch].push_back(idx);
        }

       return solve(0 , 0);
    }
};