class Solution {
public:
    typedef long long ll;
    const ll NEG = -4e18;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = LONG_MIN;
        auto solve = [&](bool flag) { // 1-> multiply 0 -> divide
            vector<ll> dp( n + 1 , NEG);
            vector<ll> dp1(n + 1, NEG);
            vector<ll> dp2(n + 1, NEG);

            for (int i = 0 ; i < n ; i++) {
                int x = nums[i];
                ll Mval = flag == true ? x * 1LL* k : x / k;

                dp[i + 1 ] = max(0LL, dp[i]) + x;  
                dp1[i + 1] = max({0LL , dp[i] , dp1[i]}) + Mval;
                dp2[i + 1] = max({dp1[i] , dp2[i]}) + x;
               ans = max({ ans ,dp[i + 1] , dp1[i + 1] , dp2[i + 1]});
            
            }
        };

        solve(true);
        solve(false);

        return ans;

    }
};