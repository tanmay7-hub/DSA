class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());

        priority_queue<int  ,vector<int> , greater<int>> pq;
        long long res = 0;
        for(auto itr : intervals ){
            int st = itr[0] , end = itr[1];

            while(!pq.empty() && pq.top() < st){
                pq.pop();
            }
            res += pq.size();
            pq.push(end);
        }

        return res;
    }
};