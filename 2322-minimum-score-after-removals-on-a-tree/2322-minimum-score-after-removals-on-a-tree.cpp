class Solution {
public:
    unordered_map<int , int > mp;
    int Precalc(unordered_map<int , vector<int>> &adj ,vector<int> &nums , int src , int par){
       
        int x = 0 ;
        for(auto v : adj[src]){
            if(par != v)
               x ^=  Precalc( adj ,nums , v , src);
        }
        mp[src] = nums[src] ^ x;
        return mp[src];
    }
    void ancestor(vector<vector<bool>> &anc , unordered_map<int , vector<int>> &adj , int src , int par){ 

         for(auto v : adj[src]){
            if(par == v) continue;
            anc[v][src] = true;

            for(int i = 0 ; i < anc.size() ; i++ ){
                anc[v][i] = (anc[v][i] || anc[src][i]); 
            }
            ancestor(anc , adj , v , src);
         }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int , vector<int>> adj;
        vector<vector<bool>> vec( n + 1 , vector<bool>(n + 1 , false));
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int total_xor = Precalc(adj ,nums, 0 , -1);
        ancestor(vec , adj , 0 , -1);
        int ans = INT_MAX;
        
        for(int i = 1 ; i <= n ; i++ ){
            for(int j = i + 1 ; j <= n ; j++){
                 int x1 = mp[i];
                 int x2 = mp[j];
                  
                 int a , b , c;
                 if(vec[j][i]){ // i ancestor
                    a = x2;
                    b = x1 ^ x2;
                    c = total_xor ^ x1;
                 }
                 else if(vec[i][j]){ // j ancestor
                    a = x1 ;
                    b = x2 ^ a;
                    c = total_xor ^ x2;
                 }else{
                    a = x1 ;
                    b = x2 ;
                    c = total_xor ^ a ^ b;
                 }
                 int curr = max({a , b , c}) - min({a , b , c});
                 ans = min(ans , curr);
            }
        }
        return ans;
    }
};