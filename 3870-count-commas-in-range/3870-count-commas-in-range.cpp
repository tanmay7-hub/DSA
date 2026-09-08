class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for(int i = 1000 ; i <= n ; i++ ){   
              int sz = log10(i)+1;
                 ans += ((sz-1)/3);

        }
        return ans;
    }
};