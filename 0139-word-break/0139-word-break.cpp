class Solution {
public:
    unordered_set<string> mp;
    unordered_map<string , bool> dp;
    bool solve(string s){
        if(s.size() == 0 )return true;
        
        if(dp.count(s)) return dp[s];
        for(int len = 1 ; len <= s.size() ; len++ ){
             string s1 = s.substr(0 , len);
             if(mp.find(s1) != mp.end()){
                if(solve(s.substr(len))){
                    return dp[s] = true;
                }
             }

        }
        return dp[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto str : wordDict){
            mp.insert(str);
        }
        return solve(s);
    }
};