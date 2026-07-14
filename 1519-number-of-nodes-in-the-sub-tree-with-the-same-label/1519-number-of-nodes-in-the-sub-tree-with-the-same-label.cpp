class Solution {
public:
    unordered_map<int,vector<int>>adj;
    string labels;
    vector<int>ans;
    vector<int> dfs( int u , int parent){
         vector<int>freq(26,0);

         freq[ labels[u] - 'a' ] ++;
         for(auto v : adj[u]){
            if(v == parent)continue;
            auto freqChild = dfs(v , u);

            for(int i = 0 ; i < 26 ;i++ ){
                freq[i] += freqChild[i];
            }
         }
         ans[u] = freq[ labels[u] - 'a' ];
         return freq;

    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this->labels = labels;
        ans.resize(n , 0);
        for( auto edge : edges ) {
                int u = edge[0];
                int v = edge[1];


                adj[u].push_back(v);
                adj[v].push_back(u);
        }
         dfs(0 , -1); 
         return ans;     
    }
};