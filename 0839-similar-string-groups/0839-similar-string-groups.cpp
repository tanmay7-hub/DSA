class Solution {
public:
     vector<int>par;
     vector<int>rank;
    int find(int x ){
        if(par[x] == x)return x;

        return par[x] = find(par[x]);
    }

    void unite(int i , int j ){
        int par_i = find(i);
        int par_j = find(j);

        if(par_i == par_j ) return ;

        if(rank[par_i] > rank[par_j]){
             rank[par_i]++;
             par[par_j] = par_i;
        }else if(rank[par_i] < rank[par_j]){
            rank[par_j]++;
             par[par_i] = par_j;
        }else{
               rank[par_i]++;
               par[par_j] = par_i;  
        }
    }
    void dfs(int root ,vector<bool>&vis, unordered_map<int,vector<int>>&adj){
        vis[root] = true;

        for(auto child : adj[root]){
            if(!vis[child]){
                dfs(child , vis , adj);
            }
        }

    }
    bool check(string s1 , string s2){
        int diff = 0;
        for(int i = 0 ; i < s1.size() ; i++ ){
            if(s1[i] != s2[i]) diff++;
        }
        return diff <= 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        par.resize(n);
        rank.resize(n , 0);
        unordered_map<int , vector<int>>adj;
        iota(begin(par) , end(par) , 0 );


        for(int i = 0 ; i < n ; i++ ){
            for(int j = i + 1 ; j < n ; j++ ){
               if(check(strs[i] , strs[j])){
                   adj[i].push_back(j);
                   adj[j].push_back(i);
                   unite(i , j );
               }
            }
        }
        int ans = 0;
        // vector<bool>visited(n , false);
        // for(int i = 0 ; i < n ; i++ ){
        //     if(!visited[i]){
        //         dfs(i,visited,adj);
        //         ans++;
        //     }
        // }
        
        for(int i = 0 ; i < n ; i++){
            if(par[i] == i )ans++;
        }
        return ans;
    }
};