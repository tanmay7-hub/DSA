class Solution {
public:
    int dp[101][101];
    int solve(string s , int idx , int curr ){
        if(curr > 0) return false;
        
        bool ans = false;

        if(dp[idx][curr + 100] != -1)return dp[idx][curr + 100];
        if(idx == s.size()){
            return curr == 0;
        }
        if(s[idx] == '('){
           ans = ans || solve(s , idx + 1 , curr - 1);
        }else if(s[idx] == ')'){
           ans = ans || solve(s , idx + 1 , curr + 1);
        }else{
            int left = solve(s , idx + 1 , curr - 1);
            int right = solve(s , idx + 1 , curr + 1);
            int space = solve (s , idx + 1 , curr);

            ans = left || right || space ;

            if(ans){
                return dp[idx][curr + 100] = true;
            }
        }

        return dp[idx][curr + 100] = ans;
    }
    bool checkValidString(string s) {
        memset(dp , -1 , sizeof(dp));
        return solve(s , 0  , 0);
    }
};