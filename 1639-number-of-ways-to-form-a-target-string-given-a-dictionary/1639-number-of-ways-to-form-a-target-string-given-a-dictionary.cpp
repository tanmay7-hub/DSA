class Solution {
public:
    vector<vector<int>> freq;
    int dp[1001][1001];
    vector<string> words;
    string target;
    int MOD = 1e9 + 7;
    long long solve( int i, int j) {// i->target , j -> curr idx;
        if(i == target.size()) return 1;
        if(j == words[0].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        long long not_take = solve( i , j + 1 ) % MOD;
        long long take = ((freq[target[i] - 'a'][j] > 0) ? solve( i + 1 , j + 1) * freq[target[i] - 'a'][j]: 0) % MOD;

         
         return dp[i][j] = ( take + not_take) % MOD;
    }
    int numWays(vector<string>& words, string target) {
        int sz = words[0].size();
        this->words = words; this->target = target;
        memset(dp , -1 , sizeof(dp));
        freq.assign(26, vector<int>(sz, 0));
        for (auto word : words) {
            for (int i = 0; i < word.size(); i++) {
                freq[word[i] - 'a'][i]++;
            }
        }
        return solve( 0, 0) % MOD;
    }
};