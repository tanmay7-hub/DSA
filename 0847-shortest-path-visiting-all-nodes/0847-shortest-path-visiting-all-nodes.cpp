class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        int target = (1 << n) -1;
        queue<pair<int , int>> q;
        vector<vector<bool>> visited(n , vector<bool>(1 << n , false));
        for(int i = 0 ; i < n ; i++ ){
            int mask = (1 << i);
            q.push({ i , mask});
            visited[i][mask] = true;
        }

        int ans = 0 ;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
               auto [node , mask] = q.front();
               q.pop();

               if(mask == target)return ans;

               for(auto neigh : graph[node]){
                   int new_mask = mask | (1 << neigh);

                   if(!visited[neigh][new_mask]){
                       visited[neigh][new_mask] = true;
                       q.push({neigh , new_mask});
                   }
               }
            }
            ans++;
        }
        return ans;
    }
};