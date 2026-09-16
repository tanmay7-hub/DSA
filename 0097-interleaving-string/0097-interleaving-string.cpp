class Solution {
public:
    string s1,  s2 , s3;
    int dp[101][101];
    bool solve( int i, int j) {
        if(i + j  == s3.size())return 1;
        if( i + j > s3.size() || (i >= s1.size() && j >= s2.size()) )return 0;

        if(dp[i][j] != -1)return dp[i][j];
        bool ans = false;
        int idx_i = i;
        int idx_k = i + j;
        while (idx_i < s1.size() && idx_k < s3.size() && s1[idx_i] == s3[idx_k]) {
            idx_i++ ; idx_k++;
            ans = ans || solve( idx_i , j );
            if(ans)  return dp[i][j] = true;
        }

        int idx_j = j;
        idx_k = i+ j;

        while(idx_j < s2.size() && idx_k < s3.size() && s2[idx_j] == s3[idx_k]){
            idx_j++; idx_k++;
            ans = ans || solve( i , idx_j );
            if(ans) return  dp[i][j] = true;
        }

        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp , -1 , sizeof(dp));
        this->s1 = s1; this->s2 = s2; this->s3 = s3;
        return solve( 0, 0);
    }
};