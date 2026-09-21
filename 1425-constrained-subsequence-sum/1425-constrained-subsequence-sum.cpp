class Solution {
public:
    //    vector<int>nums ; int k;
    //    unordered_map<string , int> dp;
    //    int solve( int idx , int prev_idx){
    //      if(idx >= nums.size()) return 0;

    //      int take = INT_MIN , not_take = INT_MIN;

    //      string key = to_string(idx) + "_" + to_string(prev_idx);
    //      if(dp.count(key))return dp[key];
    //      if(prev_idx == -1){
    //         take = nums[idx] + solve(idx + 1 , idx);
    //         not_take = solve(idx + 1 , prev_idx);
    //      }else if( idx - prev_idx <= k){
    //         take = nums[idx] + solve(idx + 1 , idx);
    //         not_take = solve(idx + 1 , prev_idx);
    //      }
    //      int ans = max(take , not_take);
    //      if(ans < 0) return 0;
    //      return dp[key] = ans ;
    //    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = nums;
        priority_queue<pair<int,int>> pq;
        // {val , idx }
        for (int i = 0; i < nums.size(); i++) {

            while(!pq.empty() && (i - pq.top().second)  > k){
                   pq.pop();
            }

            if(!pq.empty()){
                dp[i] = max(dp[i] , dp[i] + pq.top().first);
            }

            pq.push({dp[i] , i});
        }

        return *max_element(dp.begin(), dp.end());
    }
};