class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> pf(n , 0 );
        vector<int> sf(n , 0 );
        unordered_set<char> set;
        int curr = 0;
        for(int i = 0 ; i < n ; i ++ ){
               if(!set.count(s[i])){
                  curr++;
                  set.insert(s[i]);
               }
               pf[i] = curr;
        }
        
        set.clear();
        curr = 0;
        for(int i = n - 1 ; i >= 0 ; i-- ){
              if(!set.count(s[i])){
                  curr++;
                  set.insert(s[i]);
               }
               sf[i] = curr;
        }
        int ans = 0;
        for(int i = 0 ; i + 1 < n ; i ++ ){
            if(pf[i] == sf[i + 1]){
                ans ++;
            }
        }
        return ans;
    }
};