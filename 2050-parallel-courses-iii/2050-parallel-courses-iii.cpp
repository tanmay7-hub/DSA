class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>inDeg(n + 1, 0 );
        unordered_map<int , vector<int>>adj;
        for(auto vec : relations){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            inDeg[v]++;
        }
        queue<int>q;
        vector<int>fin(n + 1 , 0);
        for(int i = 1 ; i <= n ; i++ ){
            if(inDeg[i] == 0){
                 q.push(i);
                 fin[i] = time[i - 1];
            }
        }
        
        while(!q.empty()){
             int sz = q.size(); 
                  int curr = q.front();
                  q.pop();

                  for(int v : adj[curr]){
                     fin[v] = max(fin[v] , fin[curr] + time[v - 1]); 
                      inDeg[v]--;
                      if(inDeg[v] == 0 ){     
                         q.push(v);
                       }
                  }  
        }
        return *max_element(fin.begin() , fin.end());
    }
};