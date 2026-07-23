class Solution {
public:
    unordered_map<int , vector<int>>adj;
    int largestPathValue(string colors, vector<vector<int>>& edges) {
         int n = edges.size();
         int m = colors.size();
         vector<int>inDeg(m , 0);
         for( int i = 0 ; i < n ; i++ ){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            inDeg[v]++;
         }
         queue<int>q;
         vector<vector<int>>vec(m , vector<int>(26 , 0));
         for(int i = 0 ; i < m ; i++ ){
            if(inDeg[i] == 0 ){
                char ch = colors[i];
                q.push(i);
                vec[i][ch - 'a'] = 1;
            }
         }

         int countNode = 0;
         int ans = 0;
         while(!q.empty()){
            int curr = q.front();
            q.pop();
            countNode++;
            ans = max(ans , vec[curr][colors[curr] - 'a']);
            for(auto v : adj[curr]){
                for(int i = 0 ; i < 26 ; i++){
                    vec[v][i] = max( vec[v][i] ,  vec[curr][i] + ((colors[v] - 'a' == i) ? 1 : 0) );
                }
                inDeg[v]--;
                if(inDeg[v] == 0){
                    q.push(v);           
                }
            }            
         }

         if(countNode < m )return -1;


         return ans;
    }
};