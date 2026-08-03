class Solution {
public:
    vector<vector<bool>> solve(int n , vector<vector<int>>& edges ){
        vector<int> inDeg(n , 0);
        unordered_map<int , vector<int>> adj; 
        for(auto edge : edges){
            int u = edge[0] , v = edge[1];
            inDeg[v]++;
            adj[u].push_back(v);
        }
        queue<int>q;
        for(int i = 0 ; i < n ; i++ ){
            if(inDeg[i] == 0)q.push(i);
        }
        vector<vector<bool>> isReach (n , vector<bool>(n , false));
        int count = n ;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(auto v : adj[curr]){
                isReach[curr][v] = true;
                for(int i = 0 ; i < n ; i++ ){
                    if(isReach[i][curr]){
                        isReach[i][v] = true;
                    }
                }
                inDeg[v]--;
                if(inDeg[v] == 0){
                    q.push(v);
                }
            }
        }
        return  isReach;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<bool>> isReach = solve(numCourses, prerequisites);

        vector<bool>ans;
        for(auto q : queries ){
            int u = q[0] , v = q[1];

            ans.push_back(isReach[u][v]); 
        }
        return ans;
    }
};