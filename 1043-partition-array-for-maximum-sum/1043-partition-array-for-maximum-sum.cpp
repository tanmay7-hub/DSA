class Solution {
public:
    int k;
    int dp[501];
    int solve(vector<int> &arr , int idx){
        if(idx == arr.size()) return 0;
        long long ans = 0;
        
        if(dp[idx] != -1)return dp[idx];
        long long curr_max = arr[idx];
        for(int i = idx ; ((i - idx + 1 )<= k) && i < arr.size() ;i++){
            curr_max = max(curr_max , arr[i] *1LL);
            
            long long el = i - idx + 1;
            ans = max(ans , el * curr_max + solve(arr , i + 1));
        }

        return dp[idx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->k = k;
        memset(dp , -1 , sizeof(dp));
        return solve( arr , 0 );
    }
};