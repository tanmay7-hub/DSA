class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());

        int ans = 0 ;
        for(int i = 0 ; i < intervals.size() ; i++ ){
            for(int j = i + 1 ; j < intervals.size() ; j++ ){
                 if(intervals[j][0] <= intervals[i][1]){
                    ans += 1;
                 }
            }
        }
        return ans;
    }
};