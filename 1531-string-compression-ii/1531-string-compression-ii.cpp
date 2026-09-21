int dp[101][27][101][101];
class Solution {
public:   
    int solve(string &s , int i , int prev , int fre , int k){
       if(k < 0 ) return INT_MAX;
       if(i == s.size()) return 0;
       
       if(dp[i][prev][fre][k] != -1)return dp[i][prev][fre][k];
       int del = solve(s , i + 1 , prev , fre , k - 1);

       int keep = 0 ;

       if(s[i] - 'a' == prev){
           int add_more = 0;
           if(fre == 1 || fre == 9 || fre == 99 ){
              add_more = 1;
           }

           keep = add_more + solve(s , i + 1 , prev , fre + 1 , k );
       }else{
           keep =  1 + solve(s , i + 1 , s[i] - 'a' , 1 , k);

       }

       return dp[i][prev][fre][k] = min(keep , del);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp , -1 , sizeof(dp));

        return solve(s , 0 , 26 , 0 , k );
    }
};