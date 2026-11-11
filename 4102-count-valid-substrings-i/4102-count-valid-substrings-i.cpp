class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        int l = 0;
        for(int r = 0 ; r < n ; r++ ){
            if(r >= 2 && s[r- 2] == 'a' && s[r - 1] == 'b' && s[r] == 'c'){
                 l = r - 1;
            }
            ans += r - l + 1; 
        }
        return ans;
    }
};