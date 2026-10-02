class Solution {
public:
    vector<vector<int>> meetings;
    int n;
    vector<vector<long long>> dp;
    int getIdx(int curr_idx) {
        int endTime = meetings[curr_idx][1];

        return lower_bound(meetings.begin(), meetings.end(), endTime,
                           [](const vector<int>& meeting, int time) {
                               return meeting[0] < time;
                           }) -
               meetings.begin();
    }
    long long solve(int idx , bool flag) {
        if (idx == n)
            return 0;
        
        if(dp[idx][flag]  != -1)return dp[idx][flag];
        long long not_take = solve(idx + 1, flag);
        long long take =   meetings[idx][2];
        int next_idx = getIdx(idx);

        if(flag == 0){
           
           if(next_idx < n){
             take += (- meetings[idx][1]);
             take +=  solve(next_idx , 1); 
            }

        }else{

           take += meetings[idx][0];
           if(next_idx < n ){
            take +=  - meetings[idx][1] ;
            take += solve(next_idx ,  1);
           }
        }   
        return dp[idx][flag] = max(take, not_take);
    }
    long long maxEarnings(vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        this->meetings = meetings;
        n = meetings.size();
        // memset(dp , -1 , sizeof(dp));
        dp.assign(n , vector<long long>(2 , -1));
        return solve(0 , 0);
    }
};