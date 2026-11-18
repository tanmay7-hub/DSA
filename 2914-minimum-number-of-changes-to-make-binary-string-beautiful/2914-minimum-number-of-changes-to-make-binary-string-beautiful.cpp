class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0 ; i < n ; i += 2){
            int o = 0 , e = 0;
            s[i] % 2 == 0 ? e++ : o++;
            s[i + 1] % 2 == 0 ? e++ : o++;


            ans += min(o , e);
        }
        return ans;
    }
};