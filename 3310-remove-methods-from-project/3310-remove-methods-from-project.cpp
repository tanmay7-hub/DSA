class Solution {
public:
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<bool> sus(n , false);
        vector<int>inDeg(n , 0);
        for(auto edge : invocations){
            int u = edge[0];
            int v = edge[1];
            inDeg[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        q.push(k);
        sus[k] = true;
        while(!q.empty()){

            int curr = q.front();
            q.pop();

            for(auto v : adj[curr]){
                inDeg[v]--;
                if(!sus[v]){  
                    q.push(v);
                    sus[v] = true; 
                }
            }
        }

        vector<int> result;
        for(int i = 0 ; i < n ; i++){
            if(sus[i] && inDeg[i] > 0){
               vector<int> vec(n);
               iota(begin(vec) , end(vec) , 0);
               return vec;
            }else{
              if(!sus[i]) result.push_back(i);
            }
        }
        return result;
    }
};