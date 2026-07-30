class Solution {
public:
    vector<int> topo(vector<vector<int>>& edges , int& n){
        unordered_map<int,vector<int>>adj;
        vector<int>inDeg(n + 1 , 0);
        vector<int>ans;
        queue<int>q;
        int count= n ; 
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDeg[v]++;
        }
        for(int i = 1 ; i <= n ; i++ ){
            if(inDeg[i] == 0){
                 q.push(i);
            }
        }

        while(!q.empty()){
             int curr = q.front();
             q.pop();
              count--;
             ans.push_back(curr);
             for(auto v : adj[curr]){
                inDeg[v]--;
                if(inDeg[v] == 0){
                    q.push(v);
                   
                }
             }
        }

        if(count > 0)return {};

        return ans;      
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> TopoRow = topo(rowConditions , k);
        vector<int> TopoCol = topo(colConditions , k);

        if(TopoRow.empty() || TopoCol.empty()){
            return {};
        }
        vector<vector<int>>ans(k , vector<int>(k , 0));
        for(int i = 0 ; i < k ; i++ ){
            for (int j = 0 ; j < k ; j++ ){
                if(TopoRow[i] == TopoCol[j]){
                    ans[i][j] = TopoRow[i];
                }
            }
        }
        return ans;
        
    }
};