class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
       set<int> s;

       for(int i = 0 ; i < n ; i++ ) {
           s.insert(i);
       } 

       vector<int> ans ;
       for(auto q : queries){
         int u = q[0]; 
         int v = q[1];

         auto it = s.upper_bound(u);

         while(it != s.end() && *it < v) {
            it = s.erase(it);
         }

         ans.push_back(s.size() - 1);
       }
       return ans;
    }
};