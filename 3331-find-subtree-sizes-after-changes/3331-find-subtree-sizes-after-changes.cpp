class Solution {
public:
    vector<int> resultSize;
    vector<int>last;
    unordered_map<int , vector<int>> adj;

    void dfs(int node , string &s , vector<int> &par){
        int ch = s[node] - 'a';

        int lastChar = last[ch];
        last[ch] = node;

        for(auto child : adj[node]){
            dfs(child , s , par);
        }

        last[ch] = lastChar;

        if(node != 0){

            int newParent = par[node];

            if(lastChar != -1){
                newParent = last[ch];
            }

            par[node] = newParent;
            resultSize[newParent] += resultSize[node]; 
        }

    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
       int n = parent.size();
       for(int i = 0 ; i < parent.size() ; i++ ){
          int u = parent[i];
          int v = i;

          adj[u].push_back(v);
       }
       resultSize.assign(n , 1);
       last.assign(26 , -1);
    
       dfs(0 , s , parent);
       
       return resultSize;
    }
};