class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        int ans = 0;
        for(int j = 0 ; j < n - 1 ; j++ ){

            int lf[27] = {0};
            int df[27] = {0};

            unordered_set<char> mp;
            for(int i = j ; i >= 0 ; i-- ){
                  mp.insert(s[i]);
                  lf[mp.size()]++;
            }
            mp.clear();
            for(int k = j + 1 ; k <  n ; k++ ){
                mp.insert(s[k]);
                df[mp.size()]++;
            }

            for(int i = 0 ; i < 27 ; i++ ){
                ans += lf[i] * df[i];
            }
        }

        return ans;
    }
};