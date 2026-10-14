class Solution {
public:
    long long dp[100000];
    long long solve(vector<vector<long long>>& vec, int idx) {
        if (idx == vec.size())
            return 0;

        if(dp[idx] != -1)return dp[idx];
        long long not_take = solve(vec, idx + 1);

      
        int next = idx + 1;

        while (next < vec.size() && vec[next][0] <= vec[idx][0] + 2) {
            next++;
        }

        long long take = vec[idx][1] + solve(vec, next);
        return dp[idx] = max(take, not_take);
    }
    long long maximumTotalDamage(vector<int>& power) {
        memset(dp , -1 , sizeof(dp));
        vector<vector<long long>> vec;
        sort(power.begin(), power.end());
        long long curr = power[0];
        long long el = power[0];
        for (int i = 1; i < power.size(); i++) {
            if (power[i] != power[i - 1]) {
                vec.push_back({el, curr});
                curr = power[i];
                el = power[i];
            } else {

                curr += power[i];
            }
        }
        vec.push_back({el, curr});

        return solve(vec, 0);
    }
};