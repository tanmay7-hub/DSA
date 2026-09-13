class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& events , int idx , int k){
        if(idx == events.size() || k == 0 ) return 0;
        int next = events.size();
        int l = idx + 1 , r = events.size() - 1;
        
        if(dp[idx][k] != -1)return dp[idx][k];
        while(l <= r ){
            int mid = l + (r - l )/2;

            if(events[mid][0] > events[idx][1]){
                next = mid;
                r = mid - 1;
            }else{
                l = mid + 1 ;
            }
        }

        int take =events[idx][2] + solve(events , next , k - 1) ;
        int not_take = solve(events , idx + 1 , k  );
        
        return dp[idx][k] = max(take , not_take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() , events.end() );
        int n  = events.size();
        dp.assign(n ,  vector<int>(k  + 1, -1));
        return solve(events , 0  ,  k );
    }
};