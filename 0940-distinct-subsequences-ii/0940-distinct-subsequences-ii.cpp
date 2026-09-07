class Solution {
public:
    int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        long long dp = 1;
        long long last[26] = {};

        for(char ch : s ){
           int curr  = ch - 'a';
           long long newDp = (dp * 2 - last[curr] + MOD) % MOD;\
           last[curr] = dp;
           dp = newDp;
        }
        return (dp - 1+ MOD) % MOD;
    }
};