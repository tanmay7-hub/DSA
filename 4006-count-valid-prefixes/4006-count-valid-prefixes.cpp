class Solution {
public:
    int countValidPrefixes(string s) {
        int z = 0 , o = 0;
        int ans = 0 ;
        int i = 0;
        for(auto ch : s){
            if(ch == '1')o++;
            else z++;

            if(abs(z - o) <= 1 )ans++;
        }
        return ans;
    }
};