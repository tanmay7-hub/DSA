class Solution {
public:
    typedef long long ll;
    const ll NEG = -4e18;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n =  nums.size();
        ll ans = NEG;
        auto solve = [&](bool check){
            ll dp0 = NEG;
            ll dp1 = NEG;
            ll dp2 = NEG;
            for(auto x : nums){
                ll mval =( check == true )? x * 1LL *  k : x / k;
                 
                ll new_dp0 = max({0LL , dp0 }) + x;
                ll new_dp1 = max({0LL , dp0 , dp1}) + mval;
                ll new_dp2 = max({dp1 , dp2}) + x;

               
                dp0 = new_dp0;
                dp1 = new_dp1;
                dp2 = new_dp2;

                ans = max({ans , new_dp0 , new_dp1 , new_dp2}); 
            }
        };

        solve(true);
        solve(false);
        return ans;

    }
};